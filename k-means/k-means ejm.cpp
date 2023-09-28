#include <mlpack/core.hpp>
#include <bits/stdc++.h>// include basic c++ liraries
#include <mlpack/methods/kmeans/kmeans.hpp>// mlpack library for k-means
#include <armadillo>//ml pack is dependent on armadillo

using namespace arma;
using namespace mlpack;
using namespace std;

int n = 500, k = 3, max_iter = 2; // total , nro de clusters , max de iteraciones
mat dataset;
mat centroids;
Row<size_t> clusters;

void imprimir_grafica();

int main() {
	data::Load("C://Users//Joel Chavez//Desktop//proy formativo//data_ejm.csv", dataset);

	kmeans::KMeans<> mlpack_kmeans(max_iter);
	mlpack_kmeans.Cluster(dataset, k, clusters, centroids);
	
	centroids.print(" -> Centroides");
	imprimir_grafica();

	return 0;
}


void imprimir_grafica() {
	const int max = 50;
	int x, y, p[max][max / 2] = {};
	char c[5] = { 0,206,170,244,219 };

	for (int i = 0; i < n; i++) {
		x = dataset(0, i);
		y = dataset(1, i);
		p[x][y] = clusters(i) + 1;
	}

	for (int i = 0; i < k; i++) {
		x = int(centroids(0, i));
		y = int(centroids(1, i));
		p[x][y] = k + 1;
	}

	cout << "\n -> Grafica \n\n";
	for (int j = max / 2 - 1; j >= 0; j--) {
		cout << "\t";
		for (int i = 0; i < max; i++) {
			switch (p[i][j]) {
			case 1:
				cout << " " << c[1]; break;
			case 2:
				cout << " " << c[2]; break;
			case 3:
				cout << " " << c[3]; break;
			case 4:
				cout << " " << c[4]; break;
			default:
				cout << " " << c[0];
			}

		}	cout << endl;
	}	cout << endl;
}
