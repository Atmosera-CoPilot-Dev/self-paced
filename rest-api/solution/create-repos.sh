# Prompt the user to enter a personal access token
echo "Please enter your GitHub personal access token:"
read TOKEN

# Create the repository using the GitHub REST API
curl -X POST \
    -H "Authorization: token $TOKEN" \
    -H "Accept: application/vnd.github.v3+json" \
    "https://api.github.com/orgs/$ORG_NAME/repos" \
    -d "{\"name\":\"$REPO_NAME\"}"
