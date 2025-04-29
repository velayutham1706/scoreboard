# Simple Scoreboard for cricket

This is a simple scoreboard system made with the use of OpenGL library in C. You can update the score via choices! such as,
1. Ones,
2. Twos,
3. Fours,
4. Sixes,
5. Noballs,
6. Wide,
7. Wickets.


# Install OpenGL package
## In linux use this command in the terminal
```bash
sudo apt-get install freeglut3-dev
```

## For cloning this project. 
```bash
git clone https://github.com/velayutham1706/scoreboard.git

# Move to the folder
cd scoreboard

gcc score.c -lGL -lGLU -lglut -o score

# Then an executable score file will be added to your directory, run that file
./score
