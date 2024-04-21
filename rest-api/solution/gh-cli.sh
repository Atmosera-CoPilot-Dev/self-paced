# GitHub CLI api
# https://cli.github.com/manual/gh_api

# authenticate to GitHub
gh auth login 

gh api \
  -H "Accept: application/vnd.github+json" \
  -H "X-GitHub-Api-Version: 2022-11-28" \
  orgs/Atmosera-Copilot-Dev/copilot/billing

