import SwiftUI

struct EmailView: View {
    var email: Email
    var delete: (() -> Void)
    
    
    var body: some View {
        VStack{
            Text(email.sender)
            Text(email.subject)
            Text(email.summary)
            Text(email.date.formatted())
        }
        .toolbar(content: {
            Button(role: .destructive) {
                delete()
            } label: {
                Label("Delete", systemImage: "trash.fill")
            }
        })
    }
}
