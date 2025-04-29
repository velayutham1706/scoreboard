# Simple Scoreboard for cricket

This is a simple scoreboard system made with c (there is no GUI for this project). You can update the score via choices! such as,
1. Ones,
2. Twos,
3. Fours,
4. Sixes,
5. Noballs,
6. Wide,
7. Wickets.

## For cloning this project. 

## Install OpenGL package
# In linux use this command in the terminal
sudo apt-get install freeglut3-dev

```bash
git clone https://github.com/velayutham1706/scoreboard.git

# Move to the folder
cd scoreboard

gcc score.c -lGL -lGLU -lglut -o score

# Then an executable score file will be added to your directory, run that file
./score
