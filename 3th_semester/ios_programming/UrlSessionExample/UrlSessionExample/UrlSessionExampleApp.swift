//
//  UrlSessionExampleApp.swift
//  UrlSessionExample
//
//  Created by Stoyan Tinchev on 7.12.23.
//

import SwiftUI

@main
struct UrlSessionExampleApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView()
                .environmentObject(MovieListViewModel()) 
        }
    }
}
