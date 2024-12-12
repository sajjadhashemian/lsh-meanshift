#include "common.h"
#include "quickshift.h"

// Generate random data with two clusters
vector<vector<float>> generate_data(int n, int dim)
{
	vector<vector<float>> data(2 * n, vector<float>(dim));
	default_random_engine generator;
	normal_distribution<float> dist0(-90.0, 5);
	normal_distribution<float> dist1(-90.0, 5);
	normal_distribution<float> dist2(0.0, 5);
	normal_distribution<float> dist3(0.0, 5);

	for (int i = 0; i < n; ++i)
	{
		data[i][0] = dist0(generator);
		data[i][1] = dist1(generator);
		data[n + i][0] = dist2(generator);
		data[n + i][1] = dist3(generator);
	}

	return data;
}

int main()
{
	// Generate data
	int n = 5000; // Number of points per cluster
	int dim = 2;   // Dimensionality
	vector<vector<float>> data = generate_data(n, dim);
	// cout<<"Generated Data!"<<endl;
	for (int i = 0; i < 2 * n; i++)
	{
		for (int j = 0; j < dim; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}

	// QuickShift qs(sqrt(n));
	QuickShift qs(sqrt(2*n)*log2(2*n));
	// QuickShift qs(50);
	auto x = qs.fit(data);
	// auto x = qs.fast_fit(data);
	for (int y : x)
		cout << y << " ";
	cout << endl;
	return 0;
}