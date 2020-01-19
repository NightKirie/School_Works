import googlemaps

gmaps = googlemaps.Client(key = 'InputKey')

def generate_distance_matrix(address, trans):
    print(trans)
    all_to_all_distance = []
    one_to_all_distance = []
    for i in range(1, len(address)):
        one_to_all_distance = []
        for j in range(1, len(address)):
            data = gmaps.distance_matrix(address[i], address[j], mode=trans)
            if('rows' in data and len(data['rows']) and 'elements' in data['rows'][0] and len(data['rows'][0]['elements']) and 'duration' in data['rows'][0]['elements'][0] and 'value' in data['rows'][0]['elements'][0]['duration']):
                one_to_all_distance += [data['rows'][0]['elements'][0]['duration']['value']]
            else:   #for can't get the data, give a very large time value
                one_to_all_distance += [9999999]
                print("ERROR:\n" + str(data))
        all_to_all_distance += [one_to_all_distance]
    with open('map_data/'+ trans +'_value.py', 'w') as f:
        f.write("all_to_all_distance = " + str(all_to_all_distance))
    
