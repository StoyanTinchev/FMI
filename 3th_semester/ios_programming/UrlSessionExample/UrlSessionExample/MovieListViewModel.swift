//
//  MovieListViewModel.swift
//  UrlSessionExample
//
//  Created by Stoyan Tinchev on 7.12.23.
//

import Foundation

class MovieListViewModel: ObservableObject {
    @Published var movies = [Movie]()

    private let apiService = APIService()

    func loadMovies() {
        apiService.fetchMovies { [weak self] movies in
            DispatchQueue.main.async {
                self?.movies = movies ?? []
            }
        }
    }
}
