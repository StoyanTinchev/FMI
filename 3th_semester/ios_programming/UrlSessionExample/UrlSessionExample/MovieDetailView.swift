//
//  MovieDetailView.swift
//  UrlSessionExample
//
//  Created by Stoyan Tinchev on 7.12.23.
//

import SwiftUI

struct MovieDetailView: View {
    let movie: Movie
    @EnvironmentObject var viewModel: MovieListViewModel
    
    var body: some View {
        AsyncImage(url: URL(string: "https://image.tmdb.org/t/p/w500/" + movie.posterPath)) { image in
                image.resizable()
            } placeholder: {
                ProgressView()
            }
            .frame(width: 200, height: 300)
        VStack(alignment: .leading) {
            Text(movie.title)
                .font(.headline)
            Text("Release Date: \(movie.releaseDate)")
            Text(movie.overview)
                .font(.body)
        }
        .padding()
        .navigationTitle(movie.title)
    }
}
