//
//  ContentView.swift
//  iosSettings
//
//  Created by Stoyan Tinchev on 5.12.23.
//
//

import SwiftUI

struct HomeScreenView: View {
    @ObservedObject var viewModel = HomeScreenViewModel()
    var body: some View {
        NavigationStack() {
            List {
                ForEach($viewModel.ads, id: \.id) { $ad in
//                    NavigationLink {
//                        AdDetailsScreenView(ad: ad)
//                            .environmentObject(viewModel)
//                    } label: {
//                        HStack {
//                            Image(systemName: ad.image)
//                                .font(.largeTitle)
//                                .frame(width: 30)
//                            Text(ad.title)
//                                .padding(.leading, 10)
//                        }
//                    }
                    
                    NavigationLink {
                        EmptyView()
                    } label: {
                        HStack {
                            Image(systemName: ad.icon)
                                .font(.largeTitle)
                                .frame(width: 30)
                            Text(ad.title)
                                .padding(.leading, 10)
                        }
                    }
                }
            }
            
            
            .listStyle(PlainListStyle())
            .navigationTitle("Settings")
//            .navigationBarTitleDisplayMode(.inline)
            .onAppear {
                viewModel.loadAllAds()
            }
        }
    }
}

#Preview {
    HomeScreenView()
}
