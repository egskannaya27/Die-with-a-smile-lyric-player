# Die with a smile lyrics display program
## Introduction
This program is written in C and shows the lyrics of a song on the screen, one line at a time. 
It makes the lyrics appear in a way that matches the timing of the song, like a karaoke. 
The program works on both Windows and Linux based systems.

## How the Program Works
### What the Program Does
1. It shows the title of the song first.
2. Then, it displays the lyrics line by line.
3. Each character in the lyrics appears with a small delay to make it look smooth.
4. The timing of the lyrics is carefully controlled to match the song.

### How the Code is Designed
1. **Lyrics Data**:
   The lyrics are stored in a list. Each line has:
     The text of the lyric.
     The time when the line should start showing.
     The time when the line should finish.

2. **Platform-Specific Code**:
   On Windows, the program uses `Sleep` to pause and `QueryPerformanceCounter` to get the current time.
   On Unix-based systems, it uses `usleep` for pauses and `gettimeofday` for time.

3. **Timing Logic**:
   The program calculates how long each character should take to appear based on the total time for the line and the number of characters in it.
   For some lines, it uses special timing to make the display more interesting.

### Step-by-Step Flow
1. The program starts by clearing the screen and showing the song title.
2. It waits for the right time to start showing each line of lyrics.
3. For each line:
   It calculates the delay for each character.
   It shows the characters one by one with the delay.
4. After all the lyrics are shown, it displays a thank-you message and ends.

### Example of Special Timing
For the second line of the song:
The line is split into three parts:
  1. The first part has one speed.
  2. A short pause is added in the middle.
  3. The last part has a different speed.
This makes the display more dynamic and fun to watch.

## Notes
The timing for the lyrics is hardcoded. To use a different song, you need to update the lyrics and their timings in the code.
I prefere using a audio software to get the accurate timestamps.
This program is a simple example of how to use timing and text display in C.

Thank you.
Guru Sai Prasanna Eppanapally
