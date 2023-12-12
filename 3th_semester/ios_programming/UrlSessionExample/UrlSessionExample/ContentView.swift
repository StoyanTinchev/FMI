//
//  ContentView.swift
//  UrlSessionExample
//
//  Created by Stoyan Tinchev on 7.12.23.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        MovieListView()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView().environmentObject(MovieListViewModel())
    }
}
