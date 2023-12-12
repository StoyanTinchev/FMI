//
//  MovieListView.swift
//  UrlSessionExample
//
//  Created by Stoyan Tinchev on 7.12.23.
//

import SwiftUI

struct MovieListView: View {
    @StateObject var viewModel = MovieListViewModel()

    var body: some View {
        NavigationView {
            List(viewModel.movies, id: \.id) { movie in
                NavigationLink(destination: MovieDetailView(movie: movie)) {
                    Text(movie.title)
                }
            }
            .onAppear {
                viewModel.loadMovies()
            }
            .navigationTitle("Movies")
        }
    }
}
