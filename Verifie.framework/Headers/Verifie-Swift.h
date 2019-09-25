// Generated by Apple Swift version 5.0.1 (swiftlang-1001.0.82.4 clang-1001.0.46.5)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="Verifie",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif


@interface NSBundle (SWIFT_EXTENSION(Verifie))
+ (NSBundle * _Nonnull)sources SWIFT_WARN_UNUSED_RESULT;
@end

@protocol VerifieDocScannerViewControllerInterface;

SWIFT_PROTOCOL("_TtP7Verifie39DocScannerViewControllerActionsDelegate_")
@protocol DocScannerViewControllerActionsDelegate
- (void)didPressCaptureButtonDocScannerViewController:(id <VerifieDocScannerViewControllerInterface> _Nonnull)sender;
- (void)didPressCloseButtonDocScannerViewController:(id <VerifieDocScannerViewControllerInterface> _Nonnull)sender;
@end

@protocol VerifieHumanDetectorViewControllerInterface;

SWIFT_PROTOCOL("_TtP7Verifie42HumanDetectorViewControllerActionsDelegate_")
@protocol HumanDetectorViewControllerActionsDelegate
- (void)didPressCloseButtonHumanDetectorViewController:(id <VerifieHumanDetectorViewControllerInterface> _Nonnull)sender;
@end


@interface NSError (SWIFT_EXTENSION(Verifie))
/// Returns user info for Verifie error. Use only for Objective-C calls
@property (nonatomic, readonly, copy) NSDictionary<NSString *, id> * _Nullable verifieUserInfo;
@end





@class VerifieConfigs;
@protocol VerifieDelegate;

SWIFT_CLASS("_TtC7Verifie7Verifie")
@interface Verifie : NSObject
- (nonnull instancetype)initWithConfigs:(VerifieConfigs * _Nonnull)configs delegate:(id <VerifieDelegate> _Nonnull)delegate OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (void)start;
- (void)stop;
@end





@protocol VerifieBaseViewControllerDelegate;

SWIFT_PROTOCOL("_TtP7Verifie30VerifieViewControllerInterface_")
@protocol VerifieViewControllerInterface
@property (nonatomic, strong) id <VerifieBaseViewControllerDelegate> _Nullable lifeCycleDelegate;
@end

@class NSCoder;

SWIFT_CLASS("_TtC7Verifie25VerifieBaseViewController")
@interface VerifieBaseViewController : UIViewController <VerifieViewControllerInterface>
@property (nonatomic, weak) id <VerifieBaseViewControllerDelegate> _Nullable lifeCycleDelegate;
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_PROTOCOL("_TtP7Verifie33VerifieBaseViewControllerDelegate_")
@protocol VerifieBaseViewControllerDelegate
- (void)viewControllerViewDidLoad:(VerifieBaseViewController * _Nonnull)sender;
@end

@class UIColor;

SWIFT_CLASS("_TtC7Verifie19VerifieColorConfigs")
@interface VerifieColorConfigs : NSObject
/// Color for the document cropper frame and the text above. Default <code>.white</code>
@property (nonatomic, readonly, strong) UIColor * _Nonnull docCropperFrameColor;
- (nonnull instancetype)initWithDocCropperFrameColor:(UIColor * _Nonnull)docCropperFrameColor OBJC_DESIGNATED_INITIALIZER;
+ (VerifieColorConfigs * _Nonnull)default SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

enum VerifieDocumentType : NSInteger;
@class VerifieTextConfigs;
@class VerifieViewControllersConfigs;
@class VerifieDocumentScannerConfigs;

SWIFT_CLASS("_TtC7Verifie14VerifieConfigs")
@interface VerifieConfigs : NSObject
/// License key for authorization
@property (nonatomic, readonly, copy) NSString * _Nonnull licenseKey;
/// Person unique Id for identification
@property (nonatomic, readonly, copy) NSString * _Nullable personId;
/// Document type that should scan the scanner. Default <code>.unknown</code>
@property (nonatomic, readonly) enum VerifieDocumentType documentType;
/// Language ISO code. Default <code>ENG</code>
@property (nonatomic, readonly, copy) NSString * _Nonnull languageCode;
/// Visible texts configuration
@property (nonatomic, readonly, strong) VerifieTextConfigs * _Nonnull textConfigs;
/// Colors configuration
@property (nonatomic, readonly, strong) VerifieColorConfigs * _Nonnull colorConfigs;
@property (nonatomic, readonly, strong) VerifieViewControllersConfigs * _Nullable viewControllersConfigs;
/// Configurations for document scanner
@property (nonatomic, readonly, strong) VerifieDocumentScannerConfigs * _Nonnull documentScannerConfigs;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (nonnull instancetype)initWithLicenseKey:(NSString * _Nonnull)licenseKey personId:(NSString * _Nullable)personId documentType:(enum VerifieDocumentType)documentType languageCode:(NSString * _Nonnull)languageCode textConfigs:(VerifieTextConfigs * _Nonnull)textConfigs colorConfigs:(VerifieColorConfigs * _Nonnull)colorConfigs viewControllersConfigs:(VerifieViewControllersConfigs * _Nullable)viewControllersConfigs documentScannerConfigs:(VerifieDocumentScannerConfigs * _Nonnull)documentScannerConfigs OBJC_DESIGNATED_INITIALIZER;
@end

@class VerifieDocument;
@class VerifieScore;

SWIFT_PROTOCOL("_TtP7Verifie15VerifieDelegate_")
@protocol VerifieDelegate
- (void)verifie:(Verifie * _Nonnull)sender didFailWith:(NSError * _Nonnull)error;
- (UIViewController * _Nonnull)viewControllerToPresent:(Verifie * _Nonnull)sender SWIFT_WARN_UNUSED_RESULT;
- (void)verifie:(Verifie * _Nonnull)sender didReceive:(VerifieDocument * _Nonnull)document;
- (void)verifie:(Verifie * _Nonnull)sender didCalculate:(VerifieScore * _Nonnull)score;
- (void)verifieDidFinish:(Verifie * _Nonnull)sender;
@end

@class UIView;
@class VerifieVideoSessionPreviewView;
@class UILabel;
@class UIImageView;

SWIFT_PROTOCOL("_TtP7Verifie40VerifieDocScannerViewControllerInterface_")
@protocol VerifieDocScannerViewControllerInterface <VerifieViewControllerInterface>
@property (nonatomic, strong) UIView * _Null_unspecified croppingAreaView;
@property (nonatomic, strong) VerifieVideoSessionPreviewView * _Null_unspecified videoPreviewView;
@property (nonatomic, strong) UILabel * _Null_unspecified instructionsLabel;
@property (nonatomic, strong) UIImageView * _Null_unspecified croppingAreaImageView;
@property (nonatomic, strong) id <DocScannerViewControllerActionsDelegate> _Nullable actionsDelegate;
@end


SWIFT_CLASS("_TtC7Verifie15VerifieDocument")
@interface VerifieDocument : NSObject
@end

typedef SWIFT_ENUM(NSInteger, VerifieDocumentImageType, closed) {
  VerifieDocumentImageTypePassport = 0,
  VerifieDocumentImageTypeIdCard = 1,
  VerifieDocumentImageTypeIdCardBackside = 2,
};

enum ScannerOrientation : NSInteger;

SWIFT_CLASS("_TtC7Verifie29VerifieDocumentScannerConfigs")
@interface VerifieDocumentScannerConfigs : NSObject
/// Document scanner’s orientation
@property (nonatomic, readonly) enum ScannerOrientation scannerOrientation;
- (nonnull instancetype)initWithScannerOrientation:(enum ScannerOrientation)scannerOrientation OBJC_DESIGNATED_INITIALIZER;
+ (VerifieDocumentScannerConfigs * _Nonnull)default SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(NSInteger, ScannerOrientation, closed) {
  ScannerOrientationPortrait = 0,
  ScannerOrientationLandscape = 1,
};

typedef SWIFT_ENUM(NSInteger, VerifieDocumentType, closed) {
  VerifieDocumentTypeUnknown = 0,
  VerifieDocumentTypePassport = 1,
  VerifieDocumentTypeIdCard = 2,
};


SWIFT_PROTOCOL("_TtP7Verifie43VerifieHumanDetectorViewControllerInterface_")
@protocol VerifieHumanDetectorViewControllerInterface <VerifieViewControllerInterface>
@property (nonatomic, strong) VerifieVideoSessionPreviewView * _Null_unspecified previewView;
@property (nonatomic, strong) id <HumanDetectorViewControllerActionsDelegate> _Nullable actionsDelegate;
- (void)updateWithStatusText:(NSString * _Nonnull)text;
@end


SWIFT_CLASS("_TtC7Verifie12VerifieScore")
@interface VerifieScore : NSObject
@end


SWIFT_CLASS("_TtC7Verifie18VerifieTextConfigs")
@interface VerifieTextConfigs : NSObject
/// Move phone closer text. Default <code>Move phone closer</code>
@property (nonatomic, readonly, copy) NSString * _Nonnull movePhoneCloser;
/// Move phone away text. Default <code>Move phone away</code>
@property (nonatomic, readonly, copy) NSString * _Nonnull movePhoneAway;
/// Blink eyes closer text. Default <code>Blink eyes</code>
@property (nonatomic, readonly, copy) NSString * _Nonnull blinkEyes;
/// Align and Tap text. Default <code>Align and Tap</code>
@property (nonatomic, readonly, copy) NSString * _Nonnull alignTap;
/// Backside of ID text. Default <code>Backside of ID</code>
@property (nonatomic, readonly, copy) NSString * _Nonnull idBackside;
@property (nonatomic, readonly, copy) NSString * _Nonnull faceFailed;
@property (nonatomic, readonly, copy) NSString * _Nonnull eyesFailed;
@property (nonatomic, readonly, copy) NSString * _Nonnull wrongDocumentType;
- (nonnull instancetype)initWithMovePhoneCloser:(NSString * _Nonnull)movePhoneCloser movePhoneAway:(NSString * _Nonnull)movePhoneAway blinkEyes:(NSString * _Nonnull)blinkEyes alignTap:(NSString * _Nonnull)alignTap idBackside:(NSString * _Nonnull)idBackside faceFailed:(NSString * _Nonnull)faceFailed eyesFailed:(NSString * _Nonnull)eyesFailed wrongDocumentType:(NSString * _Nonnull)wrongDocumentType OBJC_DESIGNATED_INITIALIZER;
+ (VerifieTextConfigs * _Nonnull)default SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class AVCaptureVideoPreviewLayer;

SWIFT_CLASS("_TtC7Verifie30VerifieVideoSessionPreviewView")
@interface VerifieVideoSessionPreviewView : UIView
@property (nonatomic, strong) AVCaptureVideoPreviewLayer * _Nullable previewLayer;
/// Should automatically rotate video or not
@property (nonatomic) BOOL autorotate;
- (void)layoutSubviews;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end



SWIFT_CLASS("_TtC7Verifie29VerifieViewControllersConfigs")
@interface VerifieViewControllersConfigs : NSObject
/// Document scanner view controller
@property (nonatomic, readonly, strong) id <VerifieDocScannerViewControllerInterface> _Nullable documentScannerViewController;
/// Human Detector view controller
@property (nonatomic, readonly, strong) id <VerifieHumanDetectorViewControllerInterface> _Nullable humanDetectorViewController;
- (nonnull instancetype)initWithDocumentScannerViewController:(id <VerifieDocScannerViewControllerInterface> _Nullable)documentScannerViewController humanDetectorViewController:(id <VerifieHumanDetectorViewControllerInterface> _Nullable)humanDetectorViewController OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
