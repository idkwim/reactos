#ifndef SYM_FILE_H__
#define SYM_FILE_H__


/* $Id$
 *
 * PROJECT:     System regression tool for ReactOS
 * LICENSE:     GPL - See COPYING in the top level directory
 * FILE:        tools/sysreg/conf_parser.h
 * PURPOSE:     source symbol lookup
 * PROGRAMMERS: Johannes Anderwald (johannes.anderwald at sbox tugraz at)
 */

#include <string>
#include <tchar.h>
#include <map>

namespace System_
{

	typedef std::basic_string<TCHAR> string;

//---------------------------------------------------------------------------------------
///
/// class SymbolFile
///
/// Description: this class performs 2 tasks: First, it locates all available module names
/// and their associated symbol files. Secondly, it performs resolving address to source addresses
/// via the function resolveAddress
///
/// Usage: call initialize(). Then call resolveAddress();
/// i.e. resolveAddress("comctl32.dll", 0xBLABLABLA, result);

	class SymbolFile
	{
		typedef std::map<string, string> SymbolMap;
	public:
		static string VAR_ROS_OUTPUT;
//---------------------------------------------------------------------------------------
///
/// SymbolFile
///
/// Description: constructor of class SymbolFile

		SymbolFile();

//---------------------------------------------------------------------------------------
///
/// ~SymbolFile 
///
/// Description: destructor of class SymbolFile

		virtual ~SymbolFile();

//---------------------------------------------------------------------------------------
///
/// initialize
///
/// Description: this function initialize the class. It searches the subdirs 
/// of ROS_OUTPUT and adds all files with name *.nostrip.* to a map with module
/// name as the key.
///
/// Note: if the param Path is not empty, it adds all found modules to the internal
/// map
///
/// Note: if the path does not exist or the no symbol files were added then false is returned
///
/// Note: if a module with same module name is already in the map, then the new module is not added
///
/// @param Path path to ROS_OUTPUT containing symbol files
/// @return bool

		bool initialize(const string & Path = _T("output-i386"));

//---------------------------------------------------------------------------------------
///
/// resolveAddress
///
/// Description: this function attempts to resolve an address using a given symbol file
///
/// Note: the lookup is performed with raddr2line
///
/// @param module_name name of the module to examine
/// @param module_address address of the module to resolve
/// @param buffer receives information about the resolved location
/// @return bool

	bool resolveAddress(const string & module_name, const string & module_address, string & Buffer);

//---------------------------------------------------------------------------------------
///
/// getSymbolFilePath
///
/// Description: this function returns the associated FilePath to a given module name. If
/// the module name is not known, it returns false and the param FilePath remains untouched
///
/// @param ModuleName name of the module to lookup
/// @param FilePath buffer receiving the address of symbol file

	bool getSymbolFilePath(const string & ModuleName, string & FilePath);

	protected:
		SymbolMap m_Map;

	};
} // end of namespace System_



#endif /* end of SYM_FILE_H__ */
