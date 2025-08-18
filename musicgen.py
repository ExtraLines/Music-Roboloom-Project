from PIL import Image
import numpy as np
from collections import deque, defaultdict

def render(bits):
    m = len(bits)
    n = len(bits[0])
    imageArray = [[0]*n for _ in range(m)]
    
    for i in range(m):
        for j in range(n):
            if bits[i][j]:
                imageArray[i][j] = (0,0,0)
            else:
                imageArray[i][j] = (255,255,255)
    
    new_image = Image.fromarray(np.array(imageArray, dtype=np.uint8), 'RGB')
    new_image.save('music_notes.png')
    new_image.show()

def pitchToRow(note, clef):
    n = note[0]
    o = note[1]
    magicnum = 0
    row = 0
    if clef == "bass":
        magicnum = 933
    elif clef == "treble":
        magicnum = 957
    else:
        print("invalid clef")
        exit(0)
    
    row = magicnum - 2*ord(n) - 14*ord(o)
    if row < 7:
        print("Note too high: ", note)
        exit(0)
    elif row > 31:
        print("Note too low: ", note)
        exit(0)
    return row
    
    # E2 to C4 bass
    # C4 to A6 treble


def drawClef(bits, clef):
    bass = [(12, 3), (12, 4), (12, 5), (12, 6), (12, 7), 
        (13, 2), (13, 3), (13, 8), (13, 11), 
        (14, 2), (14, 3), (14, 4), (14, 8), (14, 9), 
        (16, 8), (16, 9), (17, 8), (17, 9), (17, 11), 
        (18, 7), (18, 8), (20, 6), (20, 7), (21, 5), (22, 4)]
    
    treble = [(6, 8), (7, 7), (7, 8), (7, 9), (8, 7), (8, 9), 
        (9, 7), (9, 10), (10, 7), (10, 10), 
        (12, 7), (12, 9), (12, 10), (13, 8), (13, 9), (13, 10),
        (14, 7), (14, 8), (14, 9), (16, 5), (16, 6), (16, 7), (16, 8), 
        (17, 4), (17, 5), (17, 6), (17, 8), (18, 4), (18, 5), (18, 8), 
        (20, 3), (20, 4), (20, 7), (20, 8), (20, 9), (20, 10), (20, 11), 
        (21, 3), (21, 4), (21, 6), (21, 7), (21, 9), (21, 11), (21, 12), 
        (22, 3), (22, 4), (22, 6), (22, 9), (22, 12), 
        (24, 3), (24, 4), (24, 7), (24, 9), (24, 12), 
        (25, 4), (25, 5), (25, 9), (25, 11), 
        (26, 5), (26, 6), (26, 9), (26, 10), (28, 9), 
        (29, 5), (29, 6), (29, 9), (30, 5), (30, 6), (30, 7), (30, 8), 
        (31, 6), (31, 7)]
    
    if clef == "bass":
        for (i, j) in bass:
            bits[i][j] = True
    elif clef == "treble":
        for (i,j) in treble:
            bits[i][j] = True
    else:
        print("invalid clef in drawClef")

def drawTimeSignature(bits):
    points = [(12, 18), (12, 19), (13, 18), (13, 20),
        (14, 17), (14, 19), (14, 20),
        (16, 16), (16, 19), (16, 20),
        (17, 16), (17, 17), (17, 18), (17, 19), (17, 20), (17, 21), 
        (18, 19), (18, 20)]
    
    for (i,j) in points:
        bits[i][j] = True
        bits[i+8][j] = True
        
def drawBars(bits, bars):
    for b in bars:
        for i in range(11, 27):
            bits[i][b] = True

def drawNotesAndRests(bits, measures):
    solidOnSpace = [(-1, 1), (-1, 2), (-1, 3), (-1, 4), 
        (0, 0), (0, 1), (0, 2), (0, 3), (0, 4),
        (1, 0), (1, 1), (1, 2), (1, 3)]
    
    solidOnLine = [(-2, 1), (-2, 2), (-2, 3), (-2, 4), 
        (-1, 0), (-1, 1), (-1, 2), (-1, 3), (-1, 4),
        (1, 0), (1, 1), (1, 2), (1, 3)]
    
    openOnSpace = [(-1, 1), (-1, 4), (0, 0), (0, 4),
        (1, 0), (1, 1), (1, 2), (1, 3)]
    
    openOnLine = [(-2, 1), (-2, 2), (-2, 3), (-2, 4), 
        (-1, 0), (-1, 4), (1, 0), (1, 1), (1, 2), (1, 3)]
    
    eighthUp = [(-13, 5), (-12, 5), (-11, 5),
        (-11, 6), (-10, 6), (-9, 6), (-9, 7), (-8, 7), 
        (-7, 8), (-6, 8), (-5, 8), (-4, 8), (-3, 7)]
    
    eighthDown = [(13, 1), (12, 1), (11, 1),
        (11, 2), (10, 2), (9, 2), (9, 3), (8, 3), 
        (7, 4), (6, 4), (5, 4), (4, 4), (3, 3)]
    
    eighthRest = [(-3, 0), (-3, 1), (-3, 3), 
        (-2, 0), (-2, 1), (-2, 2),
        (-1, 2), (1, 1), (2, 0), (3, 0)]
    
    quarterRest = [(-6, 0), (-6, 1), (-5, 1), (-5, 2), 
        (-3, 1), (-3, 2), (-3, 3),
        (-2, 0), (-2, 1), (-2, 2), (-2, 3), 
        (-1, 0), (-1, 1), (-1, 2), 
        (1, 0), (1, 1), (2, 1), (1, 2), 
        (3, 0), (3, 1), (3, 2), (3, 3), 
        (5, 0), (5, 1), (6, 1)]
    
    halfRest = [(-2, 0), (-2, 1), (-2, 2), (-2, 3), (-2, 4),
        (-1, 0), (-1, 1), (-1, 2), (-1, 3), (-1, 4)]
    
    wholeRest = [(-3, 0), (-3, 1), (-3, 2), (-3, 3), (-3, 4),
        (-2, 0), (-2, 1), (-2, 2), (-2, 3), (-2, 4)]
    
    for m in measures:
        for (isNote, r, c, time) in m:
            if isNote:
                if r % 4 == 3: # Line
                    if time < 4:
                        for (i,j) in solidOnLine:
                            bits[r+i][c+j] = True
                    else:
                        for (i,j) in openOnLine:
                            bits[r+i][c+j] = True
                    if time == 3 or time == 6: #dotted
                        bits[r-2][c+6] = True
                    elif time == 7: #double dotted
                        bits[r-2][c+6] = True
                        bits[r-2][c+8] = True
                        
                elif r % 4 == 1: # Space
                    if time < 4:
                        for (i,j) in solidOnSpace:
                            bits[r+i][c+j] = True
                    else:
                        for (i,j) in openOnSpace:
                            bits[r+i][c+j] = True
                    if time == 3 or time == 6: #dotted
                        bits[r][c+6] = True
                    elif time == 7: #double dotted
                        bits[r][c+6] = True
                        bits[r][c+8] = True
                        
                if r == 7 or r == 31:
                    for j in range(-1, 6):
                        bits[r][c+j] = True
                
                if r < 19: # simple stem
                    for i in range(0, 15):
                        bits[r+i][c] = True
                    if time == 1:
                        for (i,j) in eighthDown:
                            bits[r+i][c+j] = True
                else:
                    for i in range(-14, 1):
                        bits[r+i][c+4] = True
                    if time == 1:
                        for (i,j) in eighthUp:
                            bits[r+i][c+j] = True
            else: # rest
                if time == 1:
                    for (i,j) in eighthRest:
                        bits[r+i][c+j] = True
                elif time < 4:
                    for (i,j) in quarterRest:
                        bits[r+i][c+j] = True
                elif time < 8:
                    for (i,j) in halfRest:
                        bits[r+i][c+j] = True
                else:
                    for (i,j) in wholeRest:
                        bits[r+i][c+j] = True
                if time == 3 or time == 6: #dotted
                    bits[r-2][c+6] = True
                elif time == 7: #double dotted
                    bits[r-2][c+6] = True
                    bits[r-2][c+8] = True
                    
def drawAccidentals(bits, sharps, flats, naturals):
    sharpOnLine = [(-3, -4), (-3, -2), (-3, -1),
        (-2, -4), (-2, -3), (-2, -2), (-1, -5), (-1, -4), (-1, -2), 
        (1, -4), (1, -2), (1, -1),
        (2, -4), (2, -3), (2, -2), (3, -5), (3, -4), (3, -2)]
    
    sharpOnSpace = [(-4, -2), (-3, -4), (-3, -2), (-3, -1),
        (-1, -5), (-1, -4), (-1, -2), (0, -4), (0, -2),
        (1, -4), (1, -3), (1, -2), (1, -1),
        (3, -5), (3, -4), (3, -2), (4, -4)]
    
    flat = [(-8, -4), (-7, -4), (-6, -4), (-5, -4),
        (-4, -4), (-3, -4), (-2, -4), (-2, -3), (-2, -2),
        (-1, -4), (-1, -2), (0, -4), (0, -2),
        (1, -4), (1, -3), (2, -4)]
    
    naturalOnLine = [(-3, -4), (-2, -4), (-2, -3), (-2, -2),
        (-1, -4), (-1, -2), (1, -4), (1, -2),
        (2, -4), (2, -3), (2, -2), (3, -2)]
    
    naturalOnSpace = [(-4, -4), (-3, -4), (-1, -4), (-1, -2), 
        (0, -4), (0, -2), (1, -4), (1, -3), (1, -2),
        (3, -2), (4, -2)]
    
    for (r, c) in sharps:
        if r % 4 == 3: # on line
            for (i,j) in sharpOnLine:
                bits[r+i][c+j] = True
        elif r % 4 == 1:
            for (i,j) in sharpOnSpace:
                bits[r+i][c+j] = True
    for (r, c) in flats: 
        for (i,j) in flat:
            bits[r+i][c+j] = True
    for (r, c) in naturals:
        if r % 4 == 3: # on line
            for (i,j) in naturalOnLine:
                bits[r+i][c+j] = True
        elif r % 4 == 1:
            for (i,j) in naturalOnSpace:
                bits[r+i][c+j] = True
                    
            
def drawTies(bits, ties):
    for (r1, c1, r2, c2) in ties:
        dir = 1 if r1 >= 19 else -1 # compromise: does not account for beamed notes
        bits[r1+3*dir][c1+2] = True
        bits[r1+4*dir][c1+3] = True
        bits[r1+4*dir][c1+4] = True
        bits[r1+3*dir][c2+2] = True
        bits[r1+4*dir][c2+1] = True
        bits[r1+4*dir][c2] = True
        for j in range(c1+5, c2):
            bits[r1+5*dir][j] = True
        


if __name__ == "__main__":
    file = open("music_notes.txt", "r")
    
    lines = [11, 15, 19, 23, 27]
    measureLength = 8
    noteCol = 33
    nRow = 40
    
    bars = []
    ties = []
    sharps = []
    flats = []
    naturals = []
    ties = []
    
    queue = deque()
    
    clef = file.readline().strip().lower()
    
    
    for row in file:
        print(row)
        
        parse = row.split(" ")
        pitch = parse[0].lower()
        time = int(parse[1])
        
        note = pitch[0]
        if note == "r": # rest
            queue.append((False, lines[2], 0, time))
        else: # note
            octave = pitch[-1]
            r = pitchToRow(note + octave, clef)
            if pitch[1] == "+": # sharps or flats
                queue.append((True, r, 1, time))
            elif pitch[1] == "-":
                queue.append((True, r, -1, time))
            else:
                queue.append((True, r, 0, time))
                
    file.close()
    
    measures = []       
    m = []
    msize = 0
    accidental = defaultdict(lambda:0)
    tie = (0, 0)
    tieCount = 0
                
    while queue:
        (isNote, row, sf, time) = queue.popleft()
        if time + msize > measureLength:
            queue.appendleft((isNote, row, sf, time + msize - measureLength))
            time = measureLength - msize
            # if isNote, add tie here ---------------
            if isNote:
                tieCount += 1
            
        if isNote and sf != accidental[row]: # change accidental
            accidental[row] = sf
            if sf == 1:
                sharps.append((row, noteCol))
            elif sf == -1 :
                flats.append((row, noteCol))
            elif sf == 0:
                naturals.append((row, noteCol))
            
        if time == 5:
            queue.appendleft((isNote, row, sf, 1))
            m.append((isNote, row, noteCol, 4)) #add note
            msize += 4
            # if isNote, add tie here ---------------
            if isNote:
                tieCount += 1
        else:
            m.append((isNote, row, noteCol, time))
            msize += time
            
        if tie != (0, 0):
            ties.append((tie[0], tie[1], row, noteCol))
            tie = (0, 0)
        if tieCount > 0:
            tieCount -= 1
            tie = (row, noteCol)
            
            
        if(msize == measureLength):
            measures.append(m)
            m = []
            msize = 0
            accidental = defaultdict(lambda:0)
            bars.append(noteCol + 11) # bars
            noteCol += 6
        
        if(time >= 4):
            noteCol += 19
        else:
            noteCol += 12
        
    if msize > 0:
        m.append((False, lines[2], noteCol, measureLength - msize))
        measures.append(m)
        bars.append(noteCol + 11)
        bars.append(noteCol + 13)
        noteCol += 18

    print(measures)
    print(bars)
    
    bits = [[False]*noteCol for _ in range(nRow)]
    for j in range(0, noteCol, 2): # draw border
        bits[0][j] = True
        bits[2][j] = True
        bits[38][j] = True
    for j in range(1, noteCol, 2):
        bits[1][j] = True
        bits[37][j] = True
        bits[39][j] = True
    for i in lines: # draw lines
        for j in range(noteCol):
            bits[i][j] = True
            
    drawClef(bits, clef)
    
    drawTimeSignature(bits)
    
    drawBars(bits, bars)
    
    drawNotesAndRests(bits, measures)
    
    drawAccidentals(bits, sharps, flats, naturals)
    
    drawTies(bits, ties)
        
    render(bits)
    
    fileout = open("music_weave.txt", "w")
    shift = False
    for j in range(noteCol):
        fileout.write("1")
        for i in range(nRow-1, -1, -1):
            if bits[i][j]:
                fileout.write("1")
            else:
                fileout.write("0")
        fileout.write("\n")
        
        fileout.write("1")
        if shift == False:
            for i in range(nRow // 2):
                fileout.write("1")
                fileout.write("0")
            shift = True
        else:
            for i in range(nRow // 2):
                fileout.write("0")
                fileout.write("1")
            shift = False
        fileout.write("\n")
    
    fileout.close()
    print("lol")