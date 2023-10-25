def CostCalculation(path, TravellingProb):
    cost = 0
    for i in range(len(path) - 1):
        cost += TravellingProb[path[i]][path[i+1]]
    return cost

def HillClimbRacing(TravellingProb):
    VerticeCount = len(TravellingProb)
    CurrentPath = list(range(TravellingProb))
    



        