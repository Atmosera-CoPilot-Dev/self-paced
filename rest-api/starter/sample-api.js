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




