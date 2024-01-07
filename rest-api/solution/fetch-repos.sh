# Set your GitHub organization name and access token
ORG_NAME="your_organization"
ACCESS_TOKEN="your_access_token"

# Make a GET request to the GitHub API to fetch the repositories
response=$(curl -s -H "Authorization: token $ACCESS_TOKEN" "https://api.github.com/orgs/$ORG_NAME/repos")

# Extract the repository names from the response and save them to a CSV file
echo "$response" | jq -r '.[].name' | tr '\n' ',' > repos.csv
