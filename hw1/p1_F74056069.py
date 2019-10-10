import sys
from functions import func

# Calculate func(x, y) using 2 layer loop, go through each X point with all possible Y points
def brutalFormula(rangeX, rangeY):
    print("Brutal with", str(rangeX), str(rangeY))
    [rangeXMin, rangeXMax] = sorted(rangeX)
    [rangeYMin, rangeYMax] = sorted(rangeY)
    min = float('inf')
    callFuncCount = 0   # For Q2 in report
    for x in range(rangeXMin, rangeXMax+1):
        for y in range(rangeYMin, rangeXMax+1):
            z = func(x, y)
            callFuncCount += 1   # For Q2 in report
            if(z < min):
                min = z
    print("Count of calling func in brutal: ", callFuncCount)
    return "{0:.3f}".format(round(min, 3)) + "\n"

def hillClimbing(rangeX, rangeY, point, stepSize):
    print("Hill Climbing with", str(point))
    [x, y] = point
    [rangeXMin, rangeXMax] = sorted(rangeX)
    [rangeYMin, rangeYMax] = sorted(rangeY)
    min = func(x, y)
    callFuncCount = 0   # For Q2 in report
    while (x >= rangeXMin and x <= rangeXMax and y >= rangeYMin and y <= rangeYMax):
        nextStepList = []   # For storing up, down, left, right directions z value & next point, using this to find the smallest value
        # Up
        if (y + stepSize <= rangeYMax):
            z = func(x, y + stepSize)
            callFuncCount += 1   # For Q2 in report
            if(z < min):
                nextStepList.append([z, x, y + stepSize]) 
        # Down
        if (y - stepSize >= rangeYMin):
            z = func(x, y - stepSize)
            callFuncCount += 1   # For Q2 in report
            if(z < min):
                nextStepList.append([z, x, y - stepSize]) 
        # Left
        if (x - stepSize >= rangeXMin):
            z = func(x - stepSize, y)
            callFuncCount += 1   # For Q2 in report
            if(z < min):
                nextStepList.append([z, x - stepSize, y]) 
        # Right
        if (x + stepSize <= rangeXMax):
            z = func(x + stepSize, y)
            callFuncCount += 1   # For Q2 in report
            if(z < min):
                nextStepList.append([z, x + stepSize, y]) 
        # If there's no next point's z smaller than current point, break the while loop
        if(len(nextStepList) == 0):
            break
        # Sort list in ascend
        nextStepList = sorted(nextStepList, key=lambda list: list[0])  
        min = nextStepList[0][0]
        x = nextStepList[0][1]
        y = nextStepList[0][2]
    print("Count of calling func in hill climbing: ", callFuncCount,"/","{0:.3f}".format(round(min, 3)))
    return "{0:.3f}".format(round(min, 3)) + "\n"

def main():
    inputPath = ""
    outputPath = ""
    # Get input & output file path by argv, exit program if getting error command arguments
    try:
        inputPath = sys.argv[1]
        outputPath  = sys.argv[2]
    except:
        sys.exit('Error input argument! Please check your command is "python <inputfile> <outputfile>"')
    
    rangeX = [0, 0] # For range of X
    rangeY = [0, 0] # For range of Y
    pointNum = 0    # For point number
    pointList = []  # 2D array stores points
    stepSize = 1    # For hill climbing's step size
    # Try to get above value from inputPath
    with open(inputPath, 'r', encoding='utf-8') as input:
        try:
            rangeX= [int(x) for x in input.readline().strip().split(',')]
            rangeY = [int(y) for y in input.readline().strip().split(',')]
            pointNum = int(input.readline().strip())
            for i in range(0, pointNum):
                pointList.append([int(n) for n in input.readline().strip().split(',')])
        except:
            sys.exit("Error in getting data from input file! Please check if there's wrong data structure")
    
    # Write output file with both method
    with open(outputPath, 'w', encoding='utf-8') as output:
        try:
            # Brutal method
            output.write(brutalFormula(rangeX, rangeY)) 
            # Hill Climbing method
            for i in range(0, pointNum):
                output.write(hillClimbing(rangeX, rangeY, pointList[i], stepSize))
        except:
            sys.exit("Error in writing result to output file!")

        

if __name__ == '__main__':
    main()
