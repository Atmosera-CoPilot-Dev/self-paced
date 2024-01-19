# REST API

All starter files are located in the starter folder.

## Part 1 - Bash API

In file `create-repos.sh`:

1) Prompt the user to enter a personal access token
2) Create a repository using the GitHub REST API
3) Create a test for the operations

In file `fetch-repos.sh`:

1) Set GitHub organization name and access token
2) Make a GET request to the GitHub API to fetch all repositories in the organization
3) Extract the repository names from the response and save them to a CSV file named repos.csv
4) Create a test for the operations

## Part 2 - JS REST API with OctoKit

For the following, the necessary dependencies have been added to `package.json`.

1) import the Octokit library
2) import the prompt-sync library
3) prompt for personnel authentication token
4) authenticate with GitHub using a personal access token
5) display the login name of authenticated user to the console
6) use the oktokit request method to make GitHub REST API requests issues for a repository, limit the number of issues to 1 per page.
7) display repository issues to the console
8) create or use an existing repo with at least one issue to test the script.







