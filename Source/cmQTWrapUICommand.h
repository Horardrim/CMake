#ifndef cmQTWrapUICommand_h
#define cmQTWrapUICommand_h

#include "cmStandardIncludes.h"
#include "cmCommand.h"

/** \class cmQTWrapUICommand
 * \brief Create .h and .cxx files rules for QT user interfaces files
 *
 * cmQTWrapUICommand is used to create wrappers for QT classes into normal C++
 */
class cmQTWrapUICommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  virtual cmCommand* Clone() 
    {
    return new cmQTWrapUICommand;
    }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);
  
  /**
   * This is called at the end after all the information
   * specified by the command is accumulated. Most commands do
   * not implement this method.  At this point, reading and
   * writing to the cache can be done.
   */
  virtual void FinalPass();

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "QT_WRAP_UI";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "Create QT user interfaces Wrappers.";
    }
  
  /**
   * More documentation.
   */
  virtual const char* GetFullDocumentation()
    {
    return
      "QT_WRAP_UI(resultingLibraryName HeadersDestName SourcesDestName "
      "SourceLists ...)\n"
      "Produce .h and .cxx files for all the .ui file listed "
      "in the SourceLists.\n"
      "The .h files will be added to the library using the HeadersDestName\n"
      "source list.\n"
      "The .cxx files will be added to the library using the SourcesDestName\n"
      "source list.";
    }
  
private:
  /**
   * List of produced files.
   */
  std::vector<cmSourceFile> m_WrapSourcesClasses;
  std::vector<cmSourceFile> m_WrapHeadersClasses;
  /**
   * List of header files that pprovide the source for m_WrapClasses.
   */
  std::vector<std::string> m_WrapUserInterface;
  std::string m_LibraryName;
  std::string m_HeaderList;
  std::string m_SourceList;
};



#endif
