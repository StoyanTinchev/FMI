import SwiftUI

struct HomeView: View {
    @StateObject var emailFolders: EmailFolders = EmailFolders()

    var body: some View {
        NavigationView {
            List(emailFolders.folders, id: \.name) { folder in
                NavigationLink(destination: FolderView(folder: Binding.constant(folder), emailFolders: emailFolders)) {
                    HStack {
                        Image(systemName: folder.icon)
                        Text(folder.name)
                    }
                }
            }
            .navigationTitle("Папки")
        }
    }
}
