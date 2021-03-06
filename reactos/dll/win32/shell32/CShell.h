/*
 * IShellDispatch implementation
 *
 * Copyright 2015 Mark Jansen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef _SHELL_H_
#define _SHELL_H_

#undef ShellExecute

class CShell:
    public CComCoClass<CShell, &CLSID_Shell>,
    public CComObjectRootEx<CComMultiThreadModelNoCS>,
    public IDispatchImpl<IShellDispatch4, &IID_IShellDispatch4>,
    public IObjectSafety,
    public IObjectWithSite
{
private:

public:
    CShell();
    ~CShell();

    HRESULT Initialize();

    // *** IShellDispatch methods ***
    virtual HRESULT STDMETHODCALLTYPE get_Application(IDispatch **ppid);
    virtual HRESULT STDMETHODCALLTYPE get_Parent(IDispatch **ppid);
    virtual HRESULT STDMETHODCALLTYPE NameSpace(VARIANT vDir, Folder **ppsdf);
    virtual HRESULT STDMETHODCALLTYPE BrowseForFolder(LONG Hwnd, BSTR Title, LONG Options, VARIANT RootFolder, Folder **ppsdf);
    virtual HRESULT STDMETHODCALLTYPE Windows(IDispatch **ppid);
    virtual HRESULT STDMETHODCALLTYPE Open(VARIANT vDir);
    virtual HRESULT STDMETHODCALLTYPE Explore(VARIANT vDir);
    virtual HRESULT STDMETHODCALLTYPE MinimizeAll();
    virtual HRESULT STDMETHODCALLTYPE UndoMinimizeALL();
    virtual HRESULT STDMETHODCALLTYPE FileRun();
    virtual HRESULT STDMETHODCALLTYPE CascadeWindows();
    virtual HRESULT STDMETHODCALLTYPE TileVertically();
    virtual HRESULT STDMETHODCALLTYPE TileHorizontally();
    virtual HRESULT STDMETHODCALLTYPE ShutdownWindows();
    virtual HRESULT STDMETHODCALLTYPE Suspend();
    virtual HRESULT STDMETHODCALLTYPE EjectPC();
    virtual HRESULT STDMETHODCALLTYPE SetTime();
    virtual HRESULT STDMETHODCALLTYPE TrayProperties();
    virtual HRESULT STDMETHODCALLTYPE Help();
    virtual HRESULT STDMETHODCALLTYPE FindFiles();
    virtual HRESULT STDMETHODCALLTYPE FindComputer();
    virtual HRESULT STDMETHODCALLTYPE RefreshMenu();
    virtual HRESULT STDMETHODCALLTYPE ControlPanelItem(BSTR szDir);

    // *** IShellDispatch2 methods ***
    virtual HRESULT STDMETHODCALLTYPE IsRestricted(BSTR group, BSTR restriction, LONG *value);
    virtual HRESULT STDMETHODCALLTYPE ShellExecute(BSTR file, VARIANT args, VARIANT dir, VARIANT op, VARIANT show);
    virtual HRESULT STDMETHODCALLTYPE FindPrinter(BSTR name, BSTR location, BSTR model);
    virtual HRESULT STDMETHODCALLTYPE GetSystemInformation(BSTR name, VARIANT *ret);
    virtual HRESULT STDMETHODCALLTYPE ServiceStart(BSTR service, VARIANT persistent, VARIANT *ret);
    virtual HRESULT STDMETHODCALLTYPE ServiceStop(BSTR service, VARIANT persistent, VARIANT *ret);
    virtual HRESULT STDMETHODCALLTYPE IsServiceRunning(BSTR service, VARIANT *running);
    virtual HRESULT STDMETHODCALLTYPE CanStartStopService(BSTR service, VARIANT *ret);
    virtual HRESULT STDMETHODCALLTYPE ShowBrowserBar(BSTR clsid, VARIANT show, VARIANT *ret);

    // *** IShellDispatch3 methods ***
    virtual HRESULT STDMETHODCALLTYPE AddToRecent(VARIANT file, BSTR category);

    // *** IShellDispatch4 methods ***
    virtual HRESULT STDMETHODCALLTYPE WindowsSecurity();
    virtual HRESULT STDMETHODCALLTYPE ToggleDesktop();
    virtual HRESULT STDMETHODCALLTYPE ExplorerPolicy(BSTR policy, VARIANT *value);
    virtual HRESULT STDMETHODCALLTYPE GetSetting(LONG setting, VARIANT_BOOL *result);

    // *** IObjectSafety methods ***
    virtual HRESULT STDMETHODCALLTYPE GetInterfaceSafetyOptions(REFIID riid, DWORD *pdwSupportedOptions, DWORD *pdwEnabledOptions);
    virtual HRESULT STDMETHODCALLTYPE SetInterfaceSafetyOptions(REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions);

    // *** IObjectWithSite methods ***
    virtual HRESULT STDMETHODCALLTYPE SetSite(IUnknown *pUnkSite);
    virtual HRESULT STDMETHODCALLTYPE GetSite(REFIID riid, PVOID *ppvSite);


DECLARE_REGISTRY_RESOURCEID(IDR_SHELL)
DECLARE_NOT_AGGREGATABLE(CShell)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CShell)
    COM_INTERFACE_ENTRY_IID(IID_IShellDispatch4, IShellDispatch4)
    COM_INTERFACE_ENTRY_IID(IID_IShellDispatch3, IShellDispatch3)
    COM_INTERFACE_ENTRY_IID(IID_IShellDispatch2, IShellDispatch2)
    COM_INTERFACE_ENTRY_IID(IID_IShellDispatch, IShellDispatch)
    COM_INTERFACE_ENTRY_IID(IID_IDispatch, IDispatch)
    COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
    COM_INTERFACE_ENTRY_IID(IID_IObjectWithSite, IObjectWithSite)
END_COM_MAP()
};

#endif /* _SHELL_H_ */
