

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Oct 03 19:42:36 2014
 */
/* Compiler settings for _P2PWebAX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef ___P2PWebAX_h__
#define ___P2PWebAX_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAppOpt_FWD_DEFINED__
#define __IAppOpt_FWD_DEFINED__
typedef interface IAppOpt IAppOpt;

#endif 	/* __IAppOpt_FWD_DEFINED__ */


#ifndef __CAppOpt_FWD_DEFINED__
#define __CAppOpt_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAppOpt CAppOpt;
#else
typedef struct CAppOpt CAppOpt;
#endif /* __cplusplus */

#endif 	/* __CAppOpt_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"
#include "objsafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAppOpt_INTERFACE_DEFINED__
#define __IAppOpt_INTERFACE_DEFINED__

/* interface IAppOpt */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAppOpt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("759FA1AD-9B89-4E2D-925F-BA1290B76D6A")
    IAppOpt : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartApp( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopApp( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ListenPort( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServiceVersion( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateService( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAppOptVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppOpt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppOpt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppOpt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAppOpt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAppOpt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAppOpt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAppOpt * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartApp )( 
            IAppOpt * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopApp )( 
            IAppOpt * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListenPort )( 
            IAppOpt * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceVersion )( 
            IAppOpt * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateService )( 
            IAppOpt * This);
        
        END_INTERFACE
    } IAppOptVtbl;

    interface IAppOpt
    {
        CONST_VTBL struct IAppOptVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppOpt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppOpt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppOpt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppOpt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAppOpt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAppOpt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAppOpt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAppOpt_StartApp(This)	\
    ( (This)->lpVtbl -> StartApp(This) ) 

#define IAppOpt_StopApp(This)	\
    ( (This)->lpVtbl -> StopApp(This) ) 

#define IAppOpt_get_ListenPort(This,pVal)	\
    ( (This)->lpVtbl -> get_ListenPort(This,pVal) ) 

#define IAppOpt_get_ServiceVersion(This,pVal)	\
    ( (This)->lpVtbl -> get_ServiceVersion(This,pVal) ) 

#define IAppOpt_UpdateService(This)	\
    ( (This)->lpVtbl -> UpdateService(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppOpt_INTERFACE_DEFINED__ */



#ifndef __P2PWebAX_LIBRARY_DEFINED__
#define __P2PWebAX_LIBRARY_DEFINED__

/* library P2PWebAX */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_P2PWebAX;

EXTERN_C const CLSID CLSID_CAppOpt;

#ifdef __cplusplus

class DECLSPEC_UUID("E7506F35-82CD-4DCF-8F77-923A87A2D91A")
CAppOpt;
#endif
#endif /* __P2PWebAX_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


