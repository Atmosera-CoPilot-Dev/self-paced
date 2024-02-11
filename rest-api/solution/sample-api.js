// docs:  https://docs.github.com/en/rest/reference/issues#list-repository-issues

// import the Octokit library
import { Octokit } from "octokit"
// import prompt-sync library
import promptSync from 'prompt-sync';

// prompt for personnel authentication token
const prompt = promptSync();
const token = prompt('Enter your GitHub personal access token: ');

// authenticate with personal access token
const octokit = new Octokit({
       auth: token
});


// display welcome message to the console
console.log("Hello there copilot!");

// authenticate with GitHub App
const {
    data: { login },
} = await octokit.rest.users.getAuthenticated();

// display the login name of authenticated user
console.log("Hello, %s", login);


// use the oktokit request method to make GitHub REST API requests issues
// for a repository, limit the number of issues to 1 per page.

const { data } = await octokit.request("GET /repos/{owner}/{repo}/issues", {
    owner: "ORG-NAME",
    repo: "REPO-NAME",
    per_page: 10
})
// display repository issues to the console
console.log(data);
