from ortools.constraint_solver import pywrapcp
from ortools.constraint_solver import routing_enums_pb2

# Distance callback
def create_distance_callback(choose_path):
    # Create a callback to calculate distances between cities.

    def distance_callback(from_node, to_node):
        return int(choose_path[from_node][to_node])

    return distance_callback

def find_shortest_path_faster(choose_comboBoxList, choose_path, choose_address):
    tsp_size = len(choose_comboBoxList)
    num_routes = 1
    depot = 0

    # Create routing model
    if tsp_size > 0:
        routing = pywrapcp.RoutingModel(tsp_size, num_routes, depot)
        search_parameters = pywrapcp.RoutingModel.DefaultSearchParameters()
        # Create the distance callback.
        dist_callback = create_distance_callback(choose_path)
        routing.SetArcCostEvaluatorOfAllVehicles(dist_callback)
        # Solve the problem.
        assignment = routing.SolveWithParameters(search_parameters)
        if assignment:
            # Solution distance.
            time = '\n總計花費:\n' + str(int(assignment.ObjectiveValue()/60)) + "分" + \
            str(assignment.ObjectiveValue()%60) + '秒\n'
            # Display the solution.
            # Only one route here; otherwise iterate from 0 to routing.vehicles() - 1
            route_number = 0
            index = routing.Start(route_number) # Index of the variable for the starting node.
            route = "路徑:\n" 
            while not routing.IsEnd(index):
                # Convert variable indices to node indices in the displayed route.
                route += str(choose_comboBoxList[routing.IndexToNode(index)]) + '(' + \
                        str(choose_address[routing.IndexToNode(index)]) + ') -> ' + \
                        str(choose_comboBoxList[routing.IndexToNode(assignment.Value(routing.NextVar(index)))]) + '(' + \
                        str(choose_address[routing.IndexToNode(assignment.Value(routing.NextVar(index)))]) + ')\n--花費' + \
                        str(int(choose_path[routing.IndexToNode(index)][routing.IndexToNode(assignment.Value(routing.NextVar(index)))]/60)) + "分" + \
                        str(choose_path[routing.IndexToNode(index)][routing.IndexToNode(assignment.Value(routing.NextVar(index)))]%60) + "秒--\n" 
                index = assignment.Value(routing.NextVar(index))
            return route + time
        else:
            return 'No solution found.'
    else:
        return 'Specify an instance greater than 0.'
