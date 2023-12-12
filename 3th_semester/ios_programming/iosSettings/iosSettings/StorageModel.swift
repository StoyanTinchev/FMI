//
//  StorageModel.swift
//  iosSettings
//
//  Created by Stoyan Tinchev on 5.12.23.
//

import Foundation

struct StorageRow: Identifiable {
    var icon: String
    var title: String
    var id: Int
}

extension StorageRow: Hashable {
    
}

extension StorageRow {
    static var allAds: [StorageRow] {
        [
            StorageRow(icon: "watch.analog", title: "VPN", id: 102),
            StorageRow(icon: "watch.analog", title: "Екранно време", id: 103),
            StorageRow(icon: "watch.analog", title: "Основни", id: 104),
            StorageRow(icon: "watch.analog", title: "Улеснен достъп", id: 112),
            StorageRow(icon: "watch.analog", title: "Поверителност и сигурност", id: 113),
            StorageRow(icon: "watch.analog", title: "Пароли", id: 114),
            StorageRow(icon: "watch.analog", title: "Safari", id: 114),
            StorageRow(icon: "watch.analog", title: "News", id: 114),
            StorageRow(icon: "watch.analog", title: "Превод", id: 114),
            StorageRow(icon: "watch.analog", title: "Карти", id: 114),
            StorageRow(icon: "watch.analog", title: "Команди", id: 114),
        ]
    }
}

class HomeScreenViewModel: ObservableObject {
    @Published var ads: [StorageRow] = []
    private var hasBeenInitialized = false
    
    func loadAllAds() {
        if hasBeenInitialized {
            return
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 1, execute: { [weak self] in
            // code to execute
            self?.ads.append(contentsOf: StorageRow.allAds)
            self?.hasBeenInitialized = true
        })
    }
}
