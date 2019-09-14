//
//  ViewController.swift
//  Verifie
//
//  Created by mixo44 on 09/08/2019.
//  Copyright (c) 2019 mixo44. All rights reserved.
//

import UIKit
import Verifie

class ViewController: UIViewController {
    
    var verifie: Verifie!
    @IBOutlet weak var imageView: UIImageView!
    @IBOutlet weak var imageView1: UIImageView!
    @IBOutlet weak var textView: UITextView!
    
    var score: Score!
    var documents: [Document] = []
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        
        let configs = VerifieConfigs(licenseKey: "5d3f2e38-fe7c-43c6-b532-db9b57e674f8",
                                     personId: "12")
        
        verifie = Verifie(configs: configs, delegate: self)
        
        verifie.start()
    }
    
    func showAlert(with message: String) {
        
        let alertController = UIAlertController(title: nil,
                                                message: message,
                                                preferredStyle: .alert)
        
        alertController.addAction(UIAlertAction(title: "OK",
                                                style: .cancel,
                                                handler: nil))
        
        UIApplication.topViewController()?.present(alertController, animated: true, completion: nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        
        super.viewWillAppear(animated)
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
    }
}

extension ViewController: VerifieDelegate {
    
    func verifie(_ sender: Verifie, didReceive document: Document) {
        
        documents.append(document)
    }
    
    func verifie(_ sender: Verifie, didCalculate score: Score) {
        
        self.score = score
        
        sender.stop()
        
        //TODO: Remove
        var fullText = "\(String(describing: score))\n\n"
        
        for document in documents {
            
            if let imageString = document.documentFaceImage, let imageData = Data(base64Encoded: imageString) {
                
                let image = UIImage(data: imageData)
                imageView.image = image
            }
            
            fullText.append("\(String(describing: document))\n\n")
        }
        
        textView.text = fullText
        
        if
            let imageStr: String = UserDefaults.standard.string(forKey: "humanImage"),
            let imageData = Data(base64Encoded: imageStr) {
            
            let image = UIImage(data: imageData)
            imageView1.image = image
        }
        
        UserDefaults.standard.removeObject(forKey: "humanImage")
        UserDefaults.standard.synchronize()
        //
    }
    
    func verifie(_ sender: Verifie, didFailWith error: VerifieError) {
        
        showAlert(with: error.localizedDescription)
    }
    
    func viewControllerToPresent(_ sender: Verifie) -> UIViewController {
        
        return self
    }
}


extension UIApplication {
    
    class func topViewController(controller: UIViewController? = UIApplication.shared.keyWindow?.rootViewController) -> UIViewController? {
        
        if let navigationController = controller as? UINavigationController {
            return topViewController(controller: navigationController.visibleViewController)
        }
        if let tabController = controller as? UITabBarController {
            if let selected = tabController.selectedViewController {
                return topViewController(controller: selected)
            }
        }
        if let presented = controller?.presentedViewController {
            return topViewController(controller: presented)
        }
        return controller
    }
}
