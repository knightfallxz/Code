import random

graph = {
    'a': {'b': 10, 'f': 6},
    'b': {'a': 10, 'c': 19, 'e': 10},
    'c': {'b': 19, 'd': 22, 'f': 15},
    'd': {'c': 22, 'e': 5},
    'e': {'b': 10, 'd': 5, 'f': 12},
    'f': {'a': 6, 'c': 15, 'e': 12}
}

def calculate_cost(path):
    cost = 0
    for i in range(len(path) - 1):
        cost += graph[path[i]][path[i+1]]
    return cost

def generate_initial_solution():
    nodes = list(graph.keys())
    random.shuffle(nodes)
    return nodes

def generate_neighbors(solution):
    neighbors = []
    for i in range(len(solution)):
        for j in range(i+1, len(solution)):
            neighbor = solution[:]
            neighbor[i], neighbor[j] = neighbor[j], neighbor[i]
            neighbors.append(neighbor)
    return neighbors

def hill_climbing():
    current_solution = generate_initial_solution()
    current_cost = calculate_cost(current_solution)

    while True:
        neighbors = generate_neighbors(current_solution)
        best_neighbor = min(neighbors, key=lambda x: calculate_cost(x))
        best_cost = calculate_cost(best_neighbor)

        if best_cost < current_cost:
            current_solution = best_neighbor
            current_cost = best_cost
        else:
            return current_solution, current_cost

best_path, min_cost = hill_climbing()

print("Best Path:", best_path)
print("Minimum Cost:", min_cost)
