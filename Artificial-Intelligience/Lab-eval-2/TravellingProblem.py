import random

distance_matrix = [
    [0, 10, 29, 0, 0, 6],
    [10, 0, 19, 0, 0, 10],
    [29, 19, 0, 22, 0, 15],
    [0, 0, 22, 0, 5, 0],
    [0, 0, 0, 5, 0, 12],
    [6, 10, 15, 0, 12, 0]
]

def calculate_total_distance(route):
    total_distance = 0
    for i in range(len(route) - 1):
        total_distance += distance_matrix[route[i]][route[i+1]]
    total_distance += distance_matrix[route[-1]][route[0]]
    return total_distance

def tsp_hill_climbing(num_iterations, initial_route):
    current_route = initial_route
    current_cost = calculate_total_distance(current_route)

    for _ in range(num_iterations):
        neighbors = []
        for i in range(len(current_route) - 1):
            for j in range(i+1, len(current_route)):
                neighbor_route = current_route[:]
                neighbor_route[i], neighbor_route[j] = neighbor_route[j], neighbor_route[i]
                neighbors.append(neighbor_route)

        best_neighbor = min(neighbors, key=calculate_total_distance)
        best_neighbor_cost = calculate_total_distance(best_neighbor)

        if best_neighbor_cost >= current_cost:
            break

        current_route = best_neighbor
        current_cost = best_neighbor_cost

    return current_route, current_cost

cities = list(range(len(distance_matrix)))
random.shuffle(cities)
initial_route = cities

num_iterations = 1000

best_route, best_cost = tsp_hill_climbing(num_iterations, initial_route)

print("Best route:", best_route)
print("Minimum cost:", best_cost)
