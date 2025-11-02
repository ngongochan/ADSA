class CountrySystem():
    def __init__(self, data):
        country_data, build_data, destroy_data = data.split(" ")
        country_rows = country_data.split(",")
        build_rows = build_data.split(",")
        destroy_rows = destroy_data.split(",")
        total_countries = len(country_rows)
        self.length = total_countries
        self.country = [[0 for _ in range(total_countries)] for _ in range(total_countries)]
        self.build = [[None for _ in range(total_countries)] for _ in range(total_countries)]
        self.destroy = [[None for _ in range(total_countries)] for _ in range(total_countries)]
        for row_index in range(total_countries):
            for col_index in range(total_countries):
                self.country[row_index][col_index] = int(country_rows[row_index][col_index])
                self.build[row_index][col_index] = self.interpretCost(build_rows[row_index][col_index])
                self.destroy[row_index][col_index] = self.interpretCost(destroy_rows[row_index][col_index])

    def interpretCost(self, digit):
        ascii_value = ord(digit)
        if ord('a') <= ascii_value <= ord('z'):
            return ascii_value - ord('a') + 26
        if ord('A') <= ascii_value <= ord('Z'):
            return ascii_value - ord('A')
        return -1

    def optimizeCost(self):
        parent = [country_id for country_id in range(self.length)]
        rank = [0 for _ in range(self.length)]

        def find(country_id):
            return country_id if parent[country_id] == country_id else find(parent[country_id])

        def union(country_a, country_b):
            root_a = find(country_a)
            root_b = find(country_b)
            if root_a == root_b:
                return False
            else:
                if rank[root_a] >= rank[root_b]:
                    rank[root_a] += 1
                    parent[root_b] = root_a
                else:
                    parent[root_a] = root_b
                return True

        def DSU(edge_pairs):
            mst_cost = 0
            for edge_weight, start_country, end_country in edge_pairs:
                if union(start_country, end_country):
                    mst_cost += edge_weight
            return mst_cost

        edge_pairs = []
        total_destroy_cost = 0
        for start_country in range(self.length):
            for end_country in range(start_country + 1, self.length):
                if self.country[start_country][end_country] == 1:
                    total_destroy_cost += self.destroy[start_country][end_country]
                    edge_weight = -self.destroy[start_country][end_country]
                else:
                    edge_weight = self.build[start_country][end_country]
                edge_pairs.append((edge_weight, start_country, end_country))

        edge_pairs.sort(key=lambda edge: edge[0])
        mst_cost = DSU(edge_pairs)
        return mst_cost + total_destroy_cost


def main():
    data = input()
    country_system = CountrySystem(data)
    cost = country_system.optimizeCost()
    print(cost)
    return


if __name__ == "__main__":
    main()