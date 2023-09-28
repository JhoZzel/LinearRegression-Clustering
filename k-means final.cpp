#include <mlpack/core.hpp>
#include <bits/stdc++.h>// include basic c++ liraries
#include <mlpack/methods/kmeans/kmeans.hpp>// mlpack library for k-means
#include <armadillo>//ml pack is dependent on armadillo

using namespace arma;
using namespace mlpack;
using namespace std;

int k = 3, max_iter = 2; // nro de clusters , max de iteraciones
mat dataset;
mat trainData;
mat centroids;
Row<size_t> clusters;

int main() {
	// Load Data
	data::Load("C://Users//Joel Chavez//Desktop//proy formativo//data_franklin.csv", dataset);
	
	// Train Data
	trainData = dataset.cols(0, 12);// dataset.n_rows - 1
	trainData.shed_row(0);
	trainData.print(" -> Train Daata");
	
	// Build the model 'K-Means'
	kmeans::KMeans<> mlpack_kmeans(max_iter);
	mlpack_kmeans.Cluster(trainData, k, clusters, centroids);
	
	centroids.print("\n -> Centroides");
	clusters.print("\n -> Clusters");
	
	return 0;
}
