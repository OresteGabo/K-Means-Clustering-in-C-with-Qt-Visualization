# K-Means Clustering with Qt Visualization

A simple C++ implementation of the K-Means clustering algorithm with a graphical user interface built using the Qt framework for visualization. This project allows you to interactively cluster data points and visualize centroids.

## Overview

The K-Means Clustering algorithm is a popular unsupervised machine learning technique used for grouping data points into clusters. Each cluster is represented by a centroid, and the algorithm iteratively assigns data points to the nearest centroid and updates the centroids until convergence.

## Features

- Interactive GUI application for running the K-Means algorithm.
- Visualization of data points and centroids.
- Adjustable number of clusters.
- Easy-to-use interface for exploring K-Means clustering.

### Watch a Video

<iframe width="560" height="315" src="https://www.youtube.com/watch?v=fnh8xBaM--M" frameborder="0" allowfullscreen></iframe>


## Classes

### `KMean`

- Represents the K-Means algorithm.
- Responsible for generating random data points and centroids.
- Distributes data points to the nearest centroids.
- Provides access to the generated data points and centroids.

### `Position`

- Represents a data point with X and Y coordinates.
- Calculates the distance between data points.
- Can generate random positions within specified bounds.

### `Centroid`

- Extends `Position` and represents the cluster centroids.
- Keeps track of the data points assigned to each centroid.
- Can generate random centroids within specified bounds.
- Responsible for calculating new centroid positions.

## Usage

1. Clone the repository to your local machine.
2. Build the project using the provided build tools.
3. Run the application.
4. Adjust the number of clusters, and visualize data points and centroids.
5. Click "Play" to run the K-Means algorithm.

## License

This project is open-source and available under the [MIT License](LICENSE). Feel free to use it for educational and practical purposes.

## Contributions

Contributions and feedback are welcome. If you encounter any issues or have suggestions for improvement, please open an issue or submit a pull request.

## Author

Oreste Muhirwa

For inquiries, please contact Oreste Muhirwa at muhirwa.g.oreste@gmail.com.

## Acknowledgments

- The K-Means algorithm is widely used in data science and machine learning.
- The Qt framework makes it easy to create graphical user interfaces for data visualization.
