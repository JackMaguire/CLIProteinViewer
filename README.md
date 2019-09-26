# CLIProteinViewer

## What?

CLIProteinViewer is an open-source and dependency-free tool to visually inspect your protein's structure using colored text in your console, as shown below.

![CLIPV](CLIPV.png)

## Why?

It can 

## How?

### Usage

![CLIPV](CLIPV_preview.gif)

### Installation

#### 1. Clone this repository

`git clone https://github.com/JackMaguire/CLIProteinViewer.git`

#### 2. Compile

This step was designed to be as easy as possible.
Please contact me if you are running into troubles here.
There may be warnings that appear but those are fine.

```sh
cd CLIProteinViewer
bash just_install_everything_please.sh
# double-check the files ./set_CLIPV_params and ./CLIProteinViewer exist
```

#### 3. (optional) Configure

Sometimes visualization can get warped such that objects look too fat or skinny.
I did my best to fix this but it is not a generally solvable problem
because your computer's text size and font might be different than mine.
Luckily, there is a one-time fix for this.

First, make your console's text size very small (like we talked about above).
Then, run `./set_CLIPV_params` and use the left and right arrow keys to modify the circle.
The right arrow key should make it wider, the left should make it thinner.
The goal is for the circle to be as round as possible (as opposed to an oval).

When you are done, hit `q` and your settings will be saved for that computer.
