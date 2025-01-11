import os
import sys
import subprocess

WORKDIR = os.path.dirname(os.path.abspath(__file__)) + "/.."
REBASE_LIST = WORKDIR + "/.REBASE_LIST"

# Helper to run shell commands
def run_command(command, check=True):
    result = subprocess.run(command, shell=True, capture_output=True, text=True, cwd=WORKDIR)
    if check and result.returncode != 0:
        print(f"Error running command: {command}\n{result.stderr.strip()}")
        sys.exit(1)
    return result.stdout.strip()

# Verify clean working state
def check_clean_state():
    status = run_command("git status --porcelain", check=False)
    if status:
        print("Error: Uncommitted changes found. Please commit or stash them before proceeding.")
        sys.exit(1)

# Find fork point
def find_fork_point(target):
    return run_command(f"git merge-base HEAD {target}")

# Handle cherry-pick
def cherry_pick(commit):
    run_command(f"git cherry-pick -X ignore-space-change -X renormalize {commit}")

# Execute script-tagged commit
def execute_command(command):
    print(f"Executing: {command}")
    run_command(command)
    run_command("git add .")
    run_command(f"git commit -m 'script:{command}'")

# Main rebase logic
def apply(commits):
    for line in reversed(commits):
        commit = line[:8]
        message = line[10:]

        if message.startswith("script:"):
            command = message.split(":")[1].strip()
            execute_command(command)
        else:
            cherry_pick(commit)

        # Update .REBASE_LIST
        run_command("sed -i '$d' " + REBASE_LIST)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python rebase.py [<TARGET> | --continue]")
        sys.exit(1)

    target = sys.argv[1]

    if target == "--continue":
        with open(REBASE_LIST, 'r') as file:
            commits = file.readlines()
            apply(commits)
    else:
        check_clean_state()
        fork_point = find_fork_point(target)
        commits = run_command(f"git log --pretty=format:'%h: %s' --abbrev=8 {fork_point}..{target}")

        if len(sys.argv) >= 3 and sys.argv[2] == "--dry-run":
            print(commits)
            sys.exit(0)

        # Write commits to REBASE_LIST
        with open(REBASE_LIST, 'w') as file:
            file.write(commits)

        apply(commits.splitlines())

    run_command("rm " + REBASE_LIST)
