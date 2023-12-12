//
//  APIService.swift
//  UrlSessionExample
//
//  Created by Stoyan Tinchev on 7.12.23.
//

import Foundation

class APIService {
    func fetchMovies(completion: @escaping ([Movie]?) -> Void) {
        let headers = [
            "accept": "application/json",
            "Authorization": "Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiI5ZDdiNWI1MTRkNzc2YjEwZjkyMDNlNTAwNWRjMGJmZiIsInN1YiI6IjY1NzFmYjBjODg2MzQ4MDBlMzFhMzU4ZSIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ._TszecT33nGplWtdZoPUolUvlS3bvCci0Hfp4BTy7YU"
        ]

        let request = NSMutableURLRequest(url: NSURL(string: "https://api.themoviedb.org/3/discover/movie?include_adult=false&include_video=false&language=en-US&page=1&sort_by=popularity.desc")! as URL,
                                            cachePolicy: .useProtocolCachePolicy,
                                        timeoutInterval: 10.0)
        request.httpMethod = "GET"
        request.allHTTPHeaderFields = headers

        let session = URLSession.shared
        let dataTask = session.dataTask(with: request as URLRequest) { data, response, error in
            guard error == nil else {
                print(error!)
                completion(nil)
                return
            }

            if let data = data {
                let decoder = JSONDecoder()
                do {
                    let movieResponse = try decoder.decode(MovieResponse.self, from: data)
                    completion(movieResponse.results)
                } catch {
                    print(error)
                    completion(nil)
                }
            }
        }
        dataTask.resume()
    }
}

struct MovieResponse: Codable {
    let results: [Movie]
}
