# A VSCode template for Electrosmith Daisy projects

**(documentation still work in progress)**

This template supports the following features:
- import libdaisy and DaisySP directly in the workspace as git submodules (external use also supported)
- build libraries as part of the build flow (pre-built libraries also supported)
- virtual code testbench using VCV Rack

Note that since the creation of this depot, the Daisy team added vscode support to their [Examples depot](https://github.com/electro-smith/DaisyExamples)

## How to setup

DO NOT fork this repo. Clone the template instead, you have two ways of doing this:
- Using GitHub Templates - follow instructions [here](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template)
- Cloning locally - follow the instructions below

### Cloning locally

```bash
git clone --recurse-submodules https://github.com/zeroisnan/daisytmpl.git myproject
```
If you already cloned, but forgot to include submodules:
```bash
git submodule update --init --recursive
```

Disconnect your clone from this depot:
```bash
git remote rm origin
```

Create your own project in Github and push your code to it. Read more [here]( https://docs.github.com/en/free-pro-team@latest/github/importing-your-projects-to-github/adding-an-existing-project-to-github-using-the-command-line).


### Files configuration (rackbench)

The following changes are only required if you intend to use the VCV Rack virtual testbench

- Update the Makefile variable `RACK_DIR` under `rackbench/Makefile` to reflect the location of your RackSDK. This is required to build VCV Rack plugins.
- Update the env variabler `racksdk.path` under  `rackbench/.vscode/c_cpp_properties_json` to reflect the location of your Rack SDK. This is required so that VSCode can resolve include paths and lint check/suggest edits while you type your code.



https://vcvrack.com/manual/PluginDevelopmentTutorial

VCV Rack must run @ 48kHZ sampling rate as the Daisy sampling rate is hard coded in few places within the example

### Updating submodules

Update the version of the libdaisy and DaisySP submodules:
```bash
git submodule update 
git submodule foreach git checkout master 
git submodule foreach git pull origin master 
```