/**
 * Tae Won Ha — @hataewon
 *
 * http://taewon.de
 * http://qvacua.com
 *
 * See LICENSE
 */

#import <Cocoa/Cocoa.h>
#import <MacVimFramework/MacVimFramework.h>


extern NSString *const qVimArgFileNamesToOpen;
extern NSString *const qVimArgOpenFilesLayout;

@class VRMainWindowController;

@interface VRWorkspaceController : NSObject <MMVimManagerDelegateProtocol>

#pragma mark Properties
@property (weak) MMVimManager *vimManager;
@property (readonly) NSArray *workspaces;

#pragma mark Public
- (void)newWorkspace;
- (void)openFiles:(NSArray *)fileUrls;
- (void)cleanUp;

#pragma mark NSObject
- (id)init;

#pragma mark MMVimManagerDelegate
- (void)manager:(MMVimManager *)manager vimControllerCreated:(MMVimController *)vimController;
- (void)manager:(MMVimManager *)manager vimControllerRemovedWithControllerId:(unsigned int)controllerId pid:(int)pid;
- (NSMenuItem *)menuItemTemplateForManager:(MMVimManager *)manager;

@end
