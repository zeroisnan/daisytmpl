# A VSCode template for Electrosmith Daisy projects

## How to setup

DO NOT fork this repo. Clone the template instead, with:

```bash
git clone --recurse-submodules https://github.com/zeroisnan/daisytmpl.git myproject
```

Update the version of the libdaisy and DaisySP submodules:
```bash
git submodule update 
git submodule foreach git checkout master 
git submodule foreach git pull origin master 
```

Disconnect your clone from this depot:
```bash
git remote rm origin
```

Create your own project in Github and push your code to it. Read more [here]( https://docs.github.com/en/free-pro-team@latest/github/importing-your-projects-to-github/adding-an-existing-project-to-github-using-the-command-line).
