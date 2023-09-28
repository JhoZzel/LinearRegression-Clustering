#include <mlpack/core.hpp> // incluye la base componentes necesarios
#include <mlpack/methods/kmeans/kmeans.hpp> // libreria mlpack for k-means
#include <armadillo> // dependencia de mlpakc con armadillo
#include <bits/stdc++.h> // incluye librerias de c++ básicas

using namespace arma;
using namespace mlpack;
using namespace std;

const int n = 500, k = 3, max_iter = 2;
mat dataset;
mat centroids;
Row<size_t> clusters;

void imprimir_grafica();

int main() {

	data::Load("C://Users//Joel Chavez//Desktop//proy formativo//data2.csv", dataset);
	
	kmeans::KMeans<> mlpack_kmeans(max_iter);
	
	mlpack_kmeans.Cluster(dataset, k, clusters, centroids);

	centroids.print("\t Centroides");
	
	imprimir_grafica();

	return 0;
}


void imprimir_grafica() {
	const int max = 25;
	int x, y, p[max][max] = {};
	char c[5] = { 207,206,244,170,177 };

	for (int i = 0; i < n; i++) {
		x = dataset(0, i);
		y = dataset(1, i);
		p[x][y] = clusters(i) + 1;
	}

	for (int i = 0; i < k; i++) {
		x = int(centroids(0, i));
		y = int(centroids(1, i));
		p[x][y] = 4;
	}

	cout << "\n\t Grafica \n\n";
	for (int j = max-1; j >= 0; j--) {
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
				cout << "  ";
			}
		}	cout << endl;
	}	cout << endl;
}