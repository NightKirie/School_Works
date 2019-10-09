import sys
from functions import func


# Calculate func(x, y) using 2 layer loop, go through each X point with all possible Y points
def brutalFormula(rangeX, rangeY):
    min = float('inf')
    for x in range(rangeX[0], rangeX[1]+1):
        for y in range(rangeY[0], rangeY[1]+1):
            z = func(x, y)
            if(z < min):
                min = z
    return round(min, 3)

def hillClimbing():
    print("hillClimbing")

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
    # Try to get above value from inputPath
    with open(inputPath, 'r', encoding='utf-8') as input:
        try:
            rangeX = [int(x) for x in input.readline().strip().split(',')]
            rangeY = [int(y) for y in input.readline().strip().split(',')]
            pointNum = int(input.readline().strip())
            for i in range(0, pointNum):
                pointList.append([int(n) for n in input.readline().strip().split(',')])
        except:
            sys.exit("Error in getting data from input file! Please check if there's wrong data structure")
    
    # Write output file with both method
    with open(outputPath, 'w', encoding='utf-8') as output:
        output.write(brutalFormula(rangeX, rangeY))
        for i in range(0, pointNum):
            
        

if __name__ == '__main__':
    main()
