//
//  VerificationResultViewController.swift
//  VerifieFramework
//
//  Created by Misha Torosyan on 11/25/19.
//  Copyright © 2019 Misha Torosyan. All rights reserved.
//

import UIKit
import Verifie

protocol Sizeable {
    
    static var size: Int { get }
}

private enum SectionType: Int, Sizeable {
    
    case images
    case imagesData
    case documentInfo
    
    static var size: Int {
        return documentInfo.rawValue + 1
    }
}

private enum ImagesCellType: Int, Sizeable {
    
    case result
    
    static var size: Int {
        return result.rawValue + 1
    }
}

private enum ImagesDataCellType: Int, Sizeable {
    
    case score
    case liveness
    
    static var size: Int {
        return liveness.rawValue + 1
    }
}

private enum DocumentInfoCellType: Int {
    
    case documentType
    case documentNumber
    case birthDate
    case expiryDate
    case firstName
    case lastName
    case gender
    case predictedGender
    case predictedAge
    case nationality
    case country
    case documentValid
    case nextPage
    
    static var size: Int {
        return nextPage.rawValue + 1
    }
}


final class VerificationResultViewController: UIViewController {
    
    @IBOutlet weak var tableView: UITableView!
    
    var firstDocument: VerifieDocument?
    var secondDocument: VerifieDocument?
    var score: VerifieScore!
    
    
    //    MARK: - Lifecycle Functions
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
    }
    
    //    MARK: - Private Functions
    private func imagesSectionCellContent(at cellIndex: Int) -> (UIImage, UIImage) {
        
        var firstImage: UIImage?
        var secondImage: UIImage?
        
        if let documentImageDataString = firstDocument?.documentFaceImage,
            let documentImageData = Data(base64Encoded: documentImageDataString),
            let image = UIImage(data: documentImageData) {
            
            firstImage = image
        }
        
        if let scoreImageDataString = score.faceImage,
            let scoreImageData = Data(base64Encoded: scoreImageDataString),
            let image = UIImage(data: scoreImageData) {
            
            secondImage = image
        }
        
        return (firstImage ?? UIImage(), secondImage ?? UIImage())
    }
    
    private func imagesDataSectionCellContent(at cellIndex: Int) -> (String, String) {
        
        let cellType = ImagesDataCellType(rawValue: cellIndex)
        switch cellType {
        case .score:
            return ("Score", score.facialScore.description)
        case .liveness:
            return ("Liveness", score.facialLiveness.description)
        default:
            return ("Title", "Subtitle")
        }
    }
    
    private func documentInfoSectionCellContent(at cellIndex: Int) -> (String, String) {
        
        let cellType = DocumentInfoCellType(rawValue: cellIndex)
        switch cellType {
        case .documentType:
            return ("Document Type", firstDocument?.documentType ?? secondDocument?.documentType ?? "-")
        case .documentNumber:
            return ("Document Number", firstDocument?.documentNumber ?? secondDocument?.documentNumber ?? "-")
        case .birthDate:
            return ("Birth Date", firstDocument?.birthDate ?? secondDocument?.birthDate ?? "-")
        case .expiryDate:
            return ("Expiry Date", firstDocument?.expiryDate ?? secondDocument?.expiryDate ?? "_")
        case .firstName:
            return ("First Name", firstDocument?.firstname ?? secondDocument?.firstname ?? "-")
        case .lastName:
            return ("Last Name", firstDocument?.lastname ?? secondDocument?.lastname ?? "-")
        case .gender:
            return ("Gender", firstDocument?.gender ?? secondDocument?.gender ?? "-")
        case .predictedGender:
            return ("Predicted Gender", score.predictedGender)
        case .predictedAge:
            return ("Predicted Age", String(score.predictedAge))
        case .nationality:
            return ("Nationality", firstDocument?.nationality ?? secondDocument?.nationality ?? "-")
        case .country:
            return ("Country", firstDocument?.country ?? secondDocument?.country ?? "-")
        case .documentValid:
            return ("Document Valid", firstDocument?.documentValid.description ?? "-")
        case .nextPage:
            return ("Next Page", firstDocument?.nextPage.description ?? "-")
        default:
            return ("-", "-")
        }
    }
    
    
    //    MARK: - Action Functions
    @IBAction func backButtonAction(_ sender: UIBarButtonItem) {
        
        navigationController?.popViewController(animated: true)
    }
}

extension VerificationResultViewController: UITableViewDataSource {
    
    func numberOfSections(in tableView: UITableView) -> Int {
        
        return SectionType.size
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        let rowsCount: Int
        
        switch SectionType(rawValue: section) {
        case .images:
            rowsCount = ImagesCellType.size
        case .imagesData:
            rowsCount = ImagesDataCellType.size
        case .documentInfo:
            rowsCount = DocumentInfoCellType.size
        case .none:
            rowsCount = 0
        }
        
        return rowsCount
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let tableViewCell: UITableViewCell
        let sectionType = SectionType(rawValue: indexPath.section)
        
        switch sectionType {
        case .images:
            let cell = tableView.dequeueReusableCell(withIdentifier: String(describing: ImagesTableViewCell.self))! as! ImagesTableViewCell
            let (leftImage, rightImage) = imagesSectionCellContent(at: indexPath.row)
            cell.leftImageView?.image = leftImage
            cell.rightImageView?.image = rightImage
            tableViewCell = cell
        case .imagesData:
            let cell = tableView.dequeueReusableCell(withIdentifier: String(describing: InfoTableViewCell.self))! as! InfoTableViewCell
            let (title, subtitle) = imagesDataSectionCellContent(at: indexPath.row)
            cell.titleLabel?.text = title
            cell.subtitleLabel?.text = subtitle
            tableViewCell = cell
        case .documentInfo:
            let cell = tableView.dequeueReusableCell(withIdentifier: String(describing: InfoTableViewCell.self))! as! InfoTableViewCell
            let (title, subtitle) = documentInfoSectionCellContent(at: indexPath.row)
            cell.titleLabel?.text = title
            cell.subtitleLabel?.text = subtitle
            tableViewCell = cell
        case .none:
            tableViewCell = UITableViewCell()
        }
        
        return tableViewCell
    }
    
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        
        let label = UILabel()
        label.translatesAutoresizingMaskIntoConstraints = false
        label.textColor = UIColor.darkText
        label.font = UIFont.boldSystemFont(ofSize: 20)
        
        let sectionType = SectionType(rawValue: section)
        switch sectionType {
        case .images:
            label.text = "Images"
        case .imagesData:
            label.text = "Images Data"
        case .documentInfo:
            label.text = "Document Info"
        case .none:
            label.text = "-"
        }
        
        let view = UIView()
        view.addSubview(label)
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-(16)-[label]-(16)-|",
                                                           options: [],
                                                           metrics: nil,
                                                           views: ["label": label]))
        
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "V:|[label]|",
        options: [],
        metrics: nil,
        views: ["label": label]))
        
        return view
    }
}

extension VerificationResultViewController: UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        
        let sectionType = SectionType(rawValue: indexPath.section)
        switch sectionType {
        case .images:
            return 122
        default:
            return 54
        }
    }
    
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        
        return 40
    }
}
