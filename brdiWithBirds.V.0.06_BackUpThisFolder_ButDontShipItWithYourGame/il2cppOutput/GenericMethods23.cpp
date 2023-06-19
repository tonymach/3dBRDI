#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <stdint.h>
#include <limits>


template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2, T3>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3 p3)
	{
		void* params[3] = { p1, &p2, &p3 };
		method->invoker_method(methodPtr, method, obj, params, params[2]);
	}
};

struct Predicate_1_tA1131C5BA3ECE0CBC87A182D1828AD997C2E7328;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8;
struct MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C;
struct MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodInfo_t;
struct String_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct DataChannel_tBE561503DB3DE4441BD5ACE933EED98EFF70385E;
struct PeerConnection_tEC528212662B2DE9F670CB81B3839B3D6AFE3EB1;
struct OnClosedDelegate_t75BEDABCF8A8D009136C5DC48F6E1021D1A07318;
struct OnMessageBinaryDelegate_t7924B1647DD2DBCD906A1A5799A3E44A07D9CAB4;
struct OnMessageTextDelegate_tB18128C14B2F9AC751FF54DCE3210877A9C321F7;
struct OnOpenedDelegate_tD6ADF26958B29D7560252EDB6DA234BFE3AF919A;
struct OnMeshBlockRequests_t187EBB06A105F00408E15A0040CFD2215536893D;

IL2CPP_EXTERN_C RuntimeClass* Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral46AD32020556BD1DEDD130A00BF5BF6DBE698197;
IL2CPP_EXTERN_C const RuntimeMethod* Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NativeBindings_ConvertArray_TisIl2CppFullySharedGenericAny_m663E93C9296A123A8088001B61FA6405120F2BAE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NativeBindings_ConvertArray_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m7FFE868ED04F685F3E531BFD2134EED2A4FA1175_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NativeBindings_ConvertArray_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7065ADD05751F44795751825AF0B4C71977F75C4_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;

struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8;
struct MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C;
struct MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

struct MagicLeapNativeBindings_t1B3550AEC658C25E287A82013CCF193672FA2E1F  : public RuntimeObject
{
};

struct MemberInfo_t  : public RuntimeObject
{
};

struct String_t  : public RuntimeObject
{
	int32_t ____stringLength_4;
	Il2CppChar ____firstChar_5;
};

struct String_t_StaticFields
{
	String_t* ___Empty_6;
};

struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value_0;
};

struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString_5;
	String_t* ___FalseString_6;
};

struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value_0;
};

struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value_0;
};

struct IntPtr_t 
{
	void* ___m_value_0;
};

struct IntPtr_t_StaticFields
{
	intptr_t ___Zero_1;
};

struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value_0;
};

struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value_0;
};

struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

struct MLCoordinateFrameUID_t1D82997419A55FA85F35B6BF77199F28246899A4 
{
	uint64_t ___First_0;
	uint64_t ___Second_1;
};

struct MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 
{
	uint32_t ___TimeLow_0;
	uint16_t ___TimeMid_1;
	uint16_t ___TimeHiAndVersion_2;
	uint8_t ___ClockSeqHiAndReserved_3;
	uint8_t ___ClockSeqLow_4;
	uint8_t ___Node0_5;
	uint8_t ___Node1_6;
	uint8_t ___Node2_7;
	uint8_t ___Node3_8;
	uint8_t ___Node4_9;
	uint8_t ___Node5_10;
};

struct NativeBindings_tF460FFD6F75540055C859C22F81D4606B3016A7C  : public MagicLeapNativeBindings_t1B3550AEC658C25E287A82013CCF193672FA2E1F
{
};

struct NativeBindings_t4B026CFA8EFF121E050931D46B874E7D518E7D9B  : public MagicLeapNativeBindings_t1B3550AEC658C25E287A82013CCF193672FA2E1F
{
};

struct Delegate_t  : public RuntimeObject
{
	Il2CppMethodPointer ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	RuntimeObject* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	bool ___method_is_virtual_12;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

struct GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC 
{
	intptr_t ___handle_0;
};

struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value_0;
};

struct MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 
{
	MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 ___uuid_0;
	uint64_t ___size_1;
	intptr_t ___data_2;
};

struct MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 
{
	uint32_t ___Version_0;
	intptr_t ___Data_1;
	uint64_t ___DataSize_2;
	bool ___IsBinary_3;
};

struct Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8  : public RuntimeObject
{
};

struct Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_StaticFields
{
	intptr_t ___arrayPtr_0;
	OnMeshBlockRequests_t187EBB06A105F00408E15A0040CFD2215536893D* ___customBlockRequests_1;
};

struct MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E 
{
	MLCoordinateFrameUID_t1D82997419A55FA85F35B6BF77199F28246899A4 ___cfuid_0;
	int32_t ___levelOfDetail_1;
};

struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl_8;
};

struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder_0;
	Il2CppChar ___Delimiter_1;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes_2;
	RuntimeObject* ___Missing_3;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute_4;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName_5;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase_6;
};

struct DataChannel_tBE561503DB3DE4441BD5ACE933EED98EFF70385E  : public RuntimeObject
{
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ___gcHandle_0;
	uint64_t ___U3CHandleU3Ek__BackingField_1;
	OnOpenedDelegate_tD6ADF26958B29D7560252EDB6DA234BFE3AF919A* ___OnOpened_2;
	OnClosedDelegate_t75BEDABCF8A8D009136C5DC48F6E1021D1A07318* ___OnClosed_3;
	OnMessageTextDelegate_tB18128C14B2F9AC751FF54DCE3210877A9C321F7* ___OnMessageText_4;
	OnMessageBinaryDelegate_t7924B1647DD2DBCD906A1A5799A3E44A07D9CAB4* ___OnMessageBinary_5;
	String_t* ___U3CLabelU3Ek__BackingField_6;
	PeerConnection_tEC528212662B2DE9F670CB81B3839B3D6AFE3EB1* ___U3CParentConnectionU3Ek__BackingField_7;
};

struct Predicate_1_tA1131C5BA3ECE0CBC87A182D1828AD997C2E7328  : public MulticastDelegate_t
{
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
};
struct MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8  : public RuntimeArray
{
	ALIGN_FIELD (8) MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 m_Items[1];

	inline MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 value)
	{
		m_Items[index] = value;
	}
};
struct MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C  : public RuntimeArray
{
	ALIGN_FIELD (8) MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 m_Items[1];

	inline MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 value)
	{
		m_Items[index] = value;
	}
};
struct MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2  : public RuntimeArray
{
	ALIGN_FIELD (8) MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E m_Items[1];

	inline MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E value)
	{
		m_Items[index] = value;
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 Marshal_PtrToStructure_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7004C9DAA20EFE8548DF077E98E6541FA5AF9CA1_gshared (intptr_t ___ptr0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 Marshal_PtrToStructure_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m24ABC837DE2BBB228A80A801C1C9FDF8B149A920_gshared (intptr_t ___ptr0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Marshal_SizeOf_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m0926F4D331CF10B3525AC5209AD776A360E52225_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Marshal_StructureToPtr_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m6A056239AE683B7712E26FACA78552A463ED8D67_gshared (MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E ___structure0, intptr_t ___ptr1, bool ___fDeleteOld2, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032 (intptr_t* __this, const RuntimeMethod* method) ;
inline int32_t Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC (intptr_t* __this, int64_t ___value0, const RuntimeMethod* method) ;
inline MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 Marshal_PtrToStructure_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7004C9DAA20EFE8548DF077E98E6541FA5AF9CA1 (intptr_t ___ptr0, const RuntimeMethod* method)
{
	return ((  MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 (*) (intptr_t, const RuntimeMethod*))Marshal_PtrToStructure_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7004C9DAA20EFE8548DF077E98E6541FA5AF9CA1_gshared)(___ptr0, method);
}
inline MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 Marshal_PtrToStructure_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m24ABC837DE2BBB228A80A801C1C9FDF8B149A920 (intptr_t ___ptr0, const RuntimeMethod* method)
{
	return ((  MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 (*) (intptr_t, const RuntimeMethod*))Marshal_PtrToStructure_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m24ABC837DE2BBB228A80A801C1C9FDF8B149A920_gshared)(___ptr0, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t DataChannel_get_Handle_m9B0B20C580A58F01BACEAE106B2761DCAF6B2EF4_inline (DataChannel_tBE561503DB3DE4441BD5ACE933EED98EFF70385E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeBindings_MLWebRTCDataChannelSendMessage_m879797BED4C0461B29E43CAE64C5FA32ACA09F7C (uint64_t ___dataChannelHandle0, MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955* ___message1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool MLResult_DidNativeCallSucceed_m6FCBF960416DD432AB6BBF0CA6C28FAF1F834E82 (int32_t ___resultCode0, String_t* ___functionName1, Predicate_1_tA1131C5BA3ECE0CBC87A182D1828AD997C2E7328* ___successCase2, bool ___showError3, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Marshal_FreeHGlobal_m298EF0650E82E326EDA8048488DC384BB9171EB9 (intptr_t ___hglobal0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___handle0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7 (Type_t* ___t0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Marshal_AllocHGlobal_mE1D700DF967E28BE8AB3E0D67C81A96B4FCC8F4F (int32_t ___cb0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t IntPtr_Add_m97A862EB431E28787B78440412F5A6C5B84A6EEE (intptr_t ___pointer0, int32_t ___offset1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t IntPtr_op_Addition_m6887593F991D01CEB382C914B7FDFA29CB900E2A (intptr_t ___pointer0, int32_t ___offset1, const RuntimeMethod* method) ;
inline int32_t Marshal_SizeOf_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m0926F4D331CF10B3525AC5209AD776A360E52225 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))Marshal_SizeOf_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m0926F4D331CF10B3525AC5209AD776A360E52225_gshared)(method);
}
inline void Marshal_StructureToPtr_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m6A056239AE683B7712E26FACA78552A463ED8D67 (MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E ___structure0, intptr_t ___ptr1, bool ___fDeleteOld2, const RuntimeMethod* method)
{
	((  void (*) (MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E, intptr_t, bool, const RuntimeMethod*))Marshal_StructureToPtr_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m6A056239AE683B7712E26FACA78552A463ED8D67_gshared)(___structure0, ___ptr1, ___fDeleteOld2, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* NativeBindings_ConvertArray_TisIl2CppFullySharedGenericAny_m663E93C9296A123A8088001B61FA6405120F2BAE_gshared (intptr_t ___arrayPtr0, uint64_t ___count1, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeBindings_ConvertArray_TisIl2CppFullySharedGenericAny_m663E93C9296A123A8088001B61FA6405120F2BAE_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_tF2A1C9BD099680E00ABFCFBE2C2CBDB43BC0ADE7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 2));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_tF2A1C9BD099680E00ABFCFBE2C2CBDB43BC0ADE7);
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	intptr_t V_1;
	memset((&V_1), 0, sizeof(V_1));
	uint64_t V_2 = 0;
	bool V_3 = false;
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_4 = NULL;
	{
		uint64_t L_0 = ___count1;
		if ((uint64_t)(L_0) > INTPTR_MAX) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), NativeBindings_ConvertArray_TisIl2CppFullySharedGenericAny_m663E93C9296A123A8088001B61FA6405120F2BAE_RuntimeMethod_var);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(method->rgctx_data, 0), (uint32_t)((intptr_t)L_0));
		V_0 = L_1;
		intptr_t L_2 = ___arrayPtr0;
		V_1 = L_2;
		V_2 = (uint64_t)((int64_t)0);
		goto IL_003a;
	}

IL_0010:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = V_0;
		uint64_t L_4 = V_2;
		if ((uint64_t)(L_4) > INTPTR_MAX) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), NativeBindings_ConvertArray_TisIl2CppFullySharedGenericAny_m663E93C9296A123A8088001B61FA6405120F2BAE_RuntimeMethod_var);
		intptr_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		InvokerActionInvoker2< intptr_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), NULL, L_5, (Il2CppFullySharedGenericAny*)L_6);
		NullCheck(L_3);
		il2cpp_codegen_memcpy((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(((intptr_t)L_4))), L_6, SizeOf_T_tF2A1C9BD099680E00ABFCFBE2C2CBDB43BC0ADE7);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 2), (void**)(L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(((intptr_t)L_4))), (void*)L_6);
		int64_t L_7;
		L_7 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032((&V_1), NULL);
		int32_t L_8;
		L_8 = Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB(Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_RuntimeMethod_var);
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_1), ((int64_t)il2cpp_codegen_add(L_7, ((int64_t)L_8))), NULL);
		uint64_t L_9 = V_2;
		V_2 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_9, ((int64_t)1)));
	}

IL_003a:
	{
		uint64_t L_10 = V_2;
		uint64_t L_11 = ___count1;
		V_3 = (bool)((!(((uint64_t)L_10) >= ((uint64_t)L_11)))? 1 : 0);
		bool L_12 = V_3;
		if (L_12)
		{
			goto IL_0010;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_13 = V_0;
		V_4 = L_13;
		goto IL_0047;
	}

IL_0047:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = V_4;
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8* NativeBindings_ConvertArray_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7065ADD05751F44795751825AF0B4C71977F75C4_gshared (intptr_t ___arrayPtr0, uint64_t ___count1, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeBindings_ConvertArray_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7065ADD05751F44795751825AF0B4C71977F75C4_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8* V_0 = NULL;
	intptr_t V_1;
	memset((&V_1), 0, sizeof(V_1));
	uint64_t V_2 = 0;
	bool V_3 = false;
	MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8* V_4 = NULL;
	{
		uint64_t L_0 = ___count1;
		if ((uint64_t)(L_0) > INTPTR_MAX) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), NativeBindings_ConvertArray_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7065ADD05751F44795751825AF0B4C71977F75C4_RuntimeMethod_var);
		MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8* L_1 = (MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8*)(MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8*)SZArrayNew(il2cpp_rgctx_data(method->rgctx_data, 0), (uint32_t)((intptr_t)L_0));
		V_0 = L_1;
		intptr_t L_2 = ___arrayPtr0;
		V_1 = L_2;
		V_2 = (uint64_t)((int64_t)0);
		goto IL_003a;
	}

IL_0010:
	{
		MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8* L_3 = V_0;
		uint64_t L_4 = V_2;
		if ((uint64_t)(L_4) > INTPTR_MAX) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), NativeBindings_ConvertArray_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7065ADD05751F44795751825AF0B4C71977F75C4_RuntimeMethod_var);
		intptr_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9 L_6;
		L_6 = Marshal_PtrToStructure_TisMLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9_m7004C9DAA20EFE8548DF077E98E6541FA5AF9CA1(L_5, il2cpp_rgctx_method(method->rgctx_data, 1));
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(((intptr_t)L_4)), (MLUUID_tE8E69D6CF117D8C51E66C7BEB834AAA776FFF5E9)L_6);
		int64_t L_7;
		L_7 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032((&V_1), NULL);
		int32_t L_8;
		L_8 = Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB(Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_RuntimeMethod_var);
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_1), ((int64_t)il2cpp_codegen_add(L_7, ((int64_t)L_8))), NULL);
		uint64_t L_9 = V_2;
		V_2 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_9, ((int64_t)1)));
	}

IL_003a:
	{
		uint64_t L_10 = V_2;
		uint64_t L_11 = ___count1;
		V_3 = (bool)((!(((uint64_t)L_10) >= ((uint64_t)L_11)))? 1 : 0);
		bool L_12 = V_3;
		if (L_12)
		{
			goto IL_0010;
		}
	}
	{
		MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8* L_13 = V_0;
		V_4 = L_13;
		goto IL_0047;
	}

IL_0047:
	{
		MLUUIDU5BU5D_t7EB5454E10C0CC3E1B7D34906CAFE1A8CC7002F8* L_14 = V_4;
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C* NativeBindings_ConvertArray_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m7FFE868ED04F685F3E531BFD2134EED2A4FA1175_gshared (intptr_t ___arrayPtr0, uint64_t ___count1, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeBindings_ConvertArray_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m7FFE868ED04F685F3E531BFD2134EED2A4FA1175_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C* V_0 = NULL;
	intptr_t V_1;
	memset((&V_1), 0, sizeof(V_1));
	uint64_t V_2 = 0;
	bool V_3 = false;
	MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C* V_4 = NULL;
	{
		uint64_t L_0 = ___count1;
		if ((uint64_t)(L_0) > INTPTR_MAX) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), NativeBindings_ConvertArray_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m7FFE868ED04F685F3E531BFD2134EED2A4FA1175_RuntimeMethod_var);
		MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C* L_1 = (MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C*)(MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C*)SZArrayNew(il2cpp_rgctx_data(method->rgctx_data, 0), (uint32_t)((intptr_t)L_0));
		V_0 = L_1;
		intptr_t L_2 = ___arrayPtr0;
		V_1 = L_2;
		V_2 = (uint64_t)((int64_t)0);
		goto IL_003a;
	}

IL_0010:
	{
		MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C* L_3 = V_0;
		uint64_t L_4 = V_2;
		if ((uint64_t)(L_4) > INTPTR_MAX) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), NativeBindings_ConvertArray_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m7FFE868ED04F685F3E531BFD2134EED2A4FA1175_RuntimeMethod_var);
		intptr_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7 L_6;
		L_6 = Marshal_PtrToStructure_TisMLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7_m24ABC837DE2BBB228A80A801C1C9FDF8B149A920(L_5, il2cpp_rgctx_method(method->rgctx_data, 1));
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(((intptr_t)L_4)), (MLMediaPlayerPSSHEntry_t2B5A290DB66F9B1D7278BE2966A4AACAC2EE3DF7)L_6);
		int64_t L_7;
		L_7 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032((&V_1), NULL);
		int32_t L_8;
		L_8 = Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB(Marshal_SizeOf_TisIntPtr_t_m63E57DCAAB0465C36C8C5E5BD6DAB3D5C5C998AB_RuntimeMethod_var);
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_1), ((int64_t)il2cpp_codegen_add(L_7, ((int64_t)L_8))), NULL);
		uint64_t L_9 = V_2;
		V_2 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_9, ((int64_t)1)));
	}

IL_003a:
	{
		uint64_t L_10 = V_2;
		uint64_t L_11 = ___count1;
		V_3 = (bool)((!(((uint64_t)L_10) >= ((uint64_t)L_11)))? 1 : 0);
		bool L_12 = V_3;
		if (L_12)
		{
			goto IL_0010;
		}
	}
	{
		MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C* L_13 = V_0;
		V_4 = L_13;
		goto IL_0047;
	}

IL_0047:
	{
		MLMediaPlayerPSSHEntryU5BU5D_t617CBD13E0C1A3D0D9989A02B1CAD30E872F1A9C* L_14 = V_4;
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NativeBindings_SendMessageToDataChannel_TisIl2CppFullySharedGenericAny_m30BC1BAA8EF139E4402DCD12A8C54A370AED1D45_gshared (DataChannel_tBE561503DB3DE4441BD5ACE933EED98EFF70385E* ___dataChannel0, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___message1, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral46AD32020556BD1DEDD130A00BF5BF6DBE698197);
		il2cpp_rgctx_method_init(method);
	}
	MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___message1;
		MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 L_1;
		L_1 = ((  MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_1;
		DataChannel_tBE561503DB3DE4441BD5ACE933EED98EFF70385E* L_2 = ___dataChannel0;
		NullCheck(L_2);
		uint64_t L_3;
		L_3 = DataChannel_get_Handle_m9B0B20C580A58F01BACEAE106B2761DCAF6B2EF4_inline(L_2, NULL);
		int32_t L_4;
		L_4 = NativeBindings_MLWebRTCDataChannelSendMessage_m879797BED4C0461B29E43CAE64C5FA32ACA09F7C(L_3, (&V_0), NULL);
		V_1 = L_4;
		int32_t L_5 = V_1;
		bool L_6;
		L_6 = MLResult_DidNativeCallSucceed_m6FCBF960416DD432AB6BBF0CA6C28FAF1F834E82(L_5, _stringLiteral46AD32020556BD1DEDD130A00BF5BF6DBE698197, (Predicate_1_tA1131C5BA3ECE0CBC87A182D1828AD997C2E7328*)NULL, (bool)1, NULL);
		MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 L_7 = V_0;
		intptr_t L_8 = (intptr_t)L_7.___Data_1;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		Marshal_FreeHGlobal_m298EF0650E82E326EDA8048488DC384BB9171EB9(L_8, NULL);
		int32_t L_9 = V_1;
		V_2 = L_9;
		goto IL_0034;
	}

IL_0034:
	{
		int32_t L_10 = V_2;
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 MLWebRTCDataChannelMessage_Create_TisIl2CppFullySharedGenericAny_mAF1FEC29B7F6D20457F3AC9C712A7693718FAE74_gshared (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___message0, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t8AEC376B8733E5E5525DD36C7A7B4164BD67DC25 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 2));
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T_t8AEC376B8733E5E5525DD36C7A7B4164BD67DC25);
	MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	intptr_t V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	bool V_5 = false;
	MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 V_6;
	memset((&V_6), 0, sizeof(V_6));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955));
		(&V_0)->___Version_0 = (uint32_t)1;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		int32_t L_2;
		L_2 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_1, NULL);
		V_1 = L_2;
		int32_t L_3 = V_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = ___message0;
		NullCheck(L_4);
		V_2 = ((int32_t)il2cpp_codegen_multiply(L_3, ((int32_t)(((RuntimeArray*)L_4)->max_length))));
		int32_t L_5 = V_2;
		intptr_t L_6;
		L_6 = Marshal_AllocHGlobal_mE1D700DF967E28BE8AB3E0D67C81A96B4FCC8F4F(L_5, NULL);
		(&V_0)->___Data_1 = L_6;
		MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 L_7 = V_0;
		intptr_t L_8 = (intptr_t)L_7.___Data_1;
		V_3 = L_8;
		V_4 = 0;
		goto IL_0060;
	}

IL_0040:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_9 = ___message0;
		int32_t L_10 = V_4;
		NullCheck(L_9);
		int32_t L_11 = L_10;
		il2cpp_codegen_memcpy(L_12, (L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_11)), SizeOf_T_t8AEC376B8733E5E5525DD36C7A7B4164BD67DC25);
		intptr_t L_13 = V_3;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		InvokerActionInvoker3< Il2CppFullySharedGenericAny, intptr_t, bool >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), NULL, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 2)) ? L_12: *(void**)L_12), L_13, (bool)0);
		intptr_t L_14 = V_3;
		int32_t L_15 = V_1;
		intptr_t L_16;
		L_16 = IntPtr_Add_m97A862EB431E28787B78440412F5A6C5B84A6EEE(L_14, L_15, NULL);
		V_3 = L_16;
		int32_t L_17 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		int32_t L_18 = V_4;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_19 = ___message0;
		NullCheck(L_19);
		V_5 = (bool)((((int32_t)L_18) < ((int32_t)((int32_t)(((RuntimeArray*)L_19)->max_length))))? 1 : 0);
		bool L_20 = V_5;
		if (L_20)
		{
			goto IL_0040;
		}
	}
	{
		int32_t L_21 = V_2;
		(&V_0)->___DataSize_2 = (uint64_t)((int64_t)L_21);
		(&V_0)->___IsBinary_3 = (bool)1;
		MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 L_22 = V_0;
		V_6 = L_22;
		goto IL_0083;
	}

IL_0083:
	{
		MLWebRTCDataChannelMessage_tCD494F62EB56C48DFC1FB6F9334A7F7386E32955 L_23 = V_6;
		return L_23;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Config_MarshalArrayToPtr_TisIl2CppFullySharedGenericAny_mE2C5227CB640581DD92304BD70F6F98C635B97A4_gshared (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___array0, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_tAC0E132A36F2F8BE12ABB11C69ADDCD91995D4FF = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 2));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_T_tAC0E132A36F2F8BE12ABB11C69ADDCD91995D4FF);
	const Il2CppFullySharedGenericAny L_9 = alloca(SizeOf_T_tAC0E132A36F2F8BE12ABB11C69ADDCD91995D4FF);
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_1 = NULL;
	int32_t V_2 = 0;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T_tAC0E132A36F2F8BE12ABB11C69ADDCD91995D4FF);
	memset(V_3, 0, SizeOf_T_tAC0E132A36F2F8BE12ABB11C69ADDCD91995D4FF);
	intptr_t V_4;
	memset((&V_4), 0, sizeof(V_4));
	{
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = ___array0;
		NullCheck(L_1);
		intptr_t L_2;
		L_2 = Marshal_AllocHGlobal_mE1D700DF967E28BE8AB3E0D67C81A96B4FCC8F4F(((int32_t)il2cpp_codegen_multiply(L_0, ((int32_t)(((RuntimeArray*)L_1)->max_length)))), NULL);
		((Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_StaticFields*)il2cpp_codegen_static_fields_for(Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var))->___arrayPtr_0 = L_2;
		intptr_t L_3 = ((Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_StaticFields*)il2cpp_codegen_static_fields_for(Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var))->___arrayPtr_0;
		V_0 = L_3;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = ___array0;
		V_1 = L_4;
		V_2 = 0;
		goto IL_004f;
	}

IL_0021:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = V_1;
		int32_t L_6 = V_2;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		il2cpp_codegen_memcpy(L_8, (L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_7)), SizeOf_T_tAC0E132A36F2F8BE12ABB11C69ADDCD91995D4FF);
		il2cpp_codegen_memcpy(V_3, L_8, SizeOf_T_tAC0E132A36F2F8BE12ABB11C69ADDCD91995D4FF);
		il2cpp_codegen_memcpy(L_9, V_3, SizeOf_T_tAC0E132A36F2F8BE12ABB11C69ADDCD91995D4FF);
		intptr_t L_10 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		InvokerActionInvoker3< Il2CppFullySharedGenericAny, intptr_t, bool >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), NULL, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 2)) ? L_9: *(void**)L_9), L_10, (bool)1);
		int64_t L_11;
		L_11 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032((&V_0), NULL);
		intptr_t L_12;
		memset((&L_12), 0, sizeof(L_12));
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&L_12), L_11, NULL);
		int32_t L_13;
		L_13 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		intptr_t L_14;
		L_14 = IntPtr_op_Addition_m6887593F991D01CEB382C914B7FDFA29CB900E2A(L_12, L_13, NULL);
		V_0 = L_14;
		int32_t L_15 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_004f:
	{
		int32_t L_16 = V_2;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_17 = V_1;
		NullCheck(L_17);
		if ((((int32_t)L_16) < ((int32_t)((int32_t)(((RuntimeArray*)L_17)->max_length)))))
		{
			goto IL_0021;
		}
	}
	{
		intptr_t L_18 = ((Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_StaticFields*)il2cpp_codegen_static_fields_for(Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var))->___arrayPtr_0;
		V_4 = L_18;
		goto IL_005e;
	}

IL_005e:
	{
		intptr_t L_19 = V_4;
		return L_19;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Config_MarshalArrayToPtr_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m1F71E46577572774A15C07E50498A595F47F312D_gshared (MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2* ___array0, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2* V_1 = NULL;
	int32_t V_2 = 0;
	MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E V_3;
	memset((&V_3), 0, sizeof(V_3));
	intptr_t V_4;
	memset((&V_4), 0, sizeof(V_4));
	{
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		int32_t L_0;
		L_0 = Marshal_SizeOf_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m0926F4D331CF10B3525AC5209AD776A360E52225(il2cpp_rgctx_method(method->rgctx_data, 0));
		MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2* L_1 = ___array0;
		NullCheck(L_1);
		intptr_t L_2;
		L_2 = Marshal_AllocHGlobal_mE1D700DF967E28BE8AB3E0D67C81A96B4FCC8F4F(((int32_t)il2cpp_codegen_multiply(L_0, ((int32_t)(((RuntimeArray*)L_1)->max_length)))), NULL);
		((Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_StaticFields*)il2cpp_codegen_static_fields_for(Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var))->___arrayPtr_0 = L_2;
		intptr_t L_3 = ((Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_StaticFields*)il2cpp_codegen_static_fields_for(Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var))->___arrayPtr_0;
		V_0 = L_3;
		MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2* L_4 = ___array0;
		V_1 = L_4;
		V_2 = 0;
		goto IL_004f;
	}

IL_0021:
	{
		MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2* L_5 = V_1;
		int32_t L_6 = V_2;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_3 = L_8;
		MLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E L_9 = V_3;
		intptr_t L_10 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		Marshal_StructureToPtr_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m6A056239AE683B7712E26FACA78552A463ED8D67(L_9, L_10, (bool)1, il2cpp_rgctx_method(method->rgctx_data, 3));
		int64_t L_11;
		L_11 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032((&V_0), NULL);
		intptr_t L_12;
		memset((&L_12), 0, sizeof(L_12));
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&L_12), L_11, NULL);
		int32_t L_13;
		L_13 = Marshal_SizeOf_TisMLMeshingBlockRequest_tB47C895C6298A2577AFC5518BC063631D6CA6C4E_m0926F4D331CF10B3525AC5209AD776A360E52225(il2cpp_rgctx_method(method->rgctx_data, 0));
		intptr_t L_14;
		L_14 = IntPtr_op_Addition_m6887593F991D01CEB382C914B7FDFA29CB900E2A(L_12, L_13, NULL);
		V_0 = L_14;
		int32_t L_15 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_004f:
	{
		int32_t L_16 = V_2;
		MLMeshingBlockRequestU5BU5D_tCC19A6BB2522F759566030AB5C4896EC31CBE0C2* L_17 = V_1;
		NullCheck(L_17);
		if ((((int32_t)L_16) < ((int32_t)((int32_t)(((RuntimeArray*)L_17)->max_length)))))
		{
			goto IL_0021;
		}
	}
	{
		intptr_t L_18 = ((Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_StaticFields*)il2cpp_codegen_static_fields_for(Config_t14C74933A3F332644B8E6A583FAABC3C0207A3A8_il2cpp_TypeInfo_var))->___arrayPtr_0;
		V_4 = L_18;
		goto IL_005e;
	}

IL_005e:
	{
		intptr_t L_19 = V_4;
		return L_19;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t DataChannel_get_Handle_m9B0B20C580A58F01BACEAE106B2761DCAF6B2EF4_inline (DataChannel_tBE561503DB3DE4441BD5ACE933EED98EFF70385E* __this, const RuntimeMethod* method) 
{
	{
		uint64_t L_0 = __this->___U3CHandleU3Ek__BackingField_1;
		return L_0;
	}
}
