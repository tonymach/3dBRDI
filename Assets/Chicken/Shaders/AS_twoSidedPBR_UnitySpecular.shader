// Made with Amplify Shader Editor
// Available at the Unity Asset Store - http://u3d.as/y3X 
Shader "RRF_2sidedShaders/AS_twoSidedPBR_UnitySpecular"
{
	Properties
	{
		_BaseColour("BaseColour", Color) = (1,1,1,0)
		_Cutoff( "Mask Clip Value", Float ) = 0.5
		_MainTextureCutoutA("MainTexture-Cutout(A)", 2D) = "white" {}
		_SelfIllumination("SelfIllumination", Range( 0 , 2)) = 0.1
		_SpecColour("SpecColour", Color) = (1,1,1,0)
		_SpecularColTextureSmoothA("SpecularColTexture-Smooth(A)", 2D) = "white" {}
		_Smoothness("Smoothness", Range( 0 , 1)) = 0.5
		_NormalMap("NormalMap", 2D) = "bump" {}
		[HideInInspector] _texcoord( "", 2D ) = "white" {}
		[HideInInspector] __dirty( "", Int ) = 1
	}

	SubShader
	{
		Tags{ "RenderType" = "TransparentCutout"  "Queue" = "Geometry+0" "IsEmissive" = "true"  }
		Cull Off
		CGPROGRAM
		#pragma target 3.0
		#pragma surface surf StandardSpecular keepalpha addshadow fullforwardshadows 
		struct Input
		{
			float2 uv_texcoord;
			half ASEVFace : VFACE;
		};

		uniform sampler2D _NormalMap;
		uniform float4 _NormalMap_ST;
		uniform float4 _BaseColour;
		uniform sampler2D _MainTextureCutoutA;
		uniform float4 _MainTextureCutoutA_ST;
		uniform float _SelfIllumination;
		uniform float4 _SpecColour;
		uniform sampler2D _SpecularColTextureSmoothA;
		uniform float4 _SpecularColTextureSmoothA_ST;
		uniform float _Smoothness;
		uniform float _Cutoff = 0.5;

		void surf( Input i , inout SurfaceOutputStandardSpecular o )
		{
			float2 uv_NormalMap = i.uv_texcoord * _NormalMap_ST.xy + _NormalMap_ST.zw;
			float3 tex2DNode20 = UnpackNormal( tex2D( _NormalMap, uv_NormalMap ) );
			float3 appendResult40 = (float3(tex2DNode20.r , tex2DNode20.g , ( tex2DNode20.b * -1.0 )));
			float3 switchResult39 = (((i.ASEVFace>0)?(tex2DNode20):(appendResult40)));
			o.Normal = switchResult39;
			float2 uv_MainTextureCutoutA = i.uv_texcoord * _MainTextureCutoutA_ST.xy + _MainTextureCutoutA_ST.zw;
			float4 tex2DNode10 = tex2D( _MainTextureCutoutA, uv_MainTextureCutoutA );
			float4 temp_output_11_0 = ( _BaseColour * tex2DNode10 );
			o.Albedo = temp_output_11_0.rgb;
			o.Emission = ( temp_output_11_0 * _SelfIllumination ).rgb;
			float2 uv_SpecularColTextureSmoothA = i.uv_texcoord * _SpecularColTextureSmoothA_ST.xy + _SpecularColTextureSmoothA_ST.zw;
			float4 tex2DNode19 = tex2D( _SpecularColTextureSmoothA, uv_SpecularColTextureSmoothA );
			o.Specular = ( _SpecColour * tex2DNode19 ).rgb;
			o.Smoothness = ( _Smoothness * tex2DNode19.b );
			o.Alpha = 1;
			clip( tex2DNode10.a - _Cutoff );
		}

		ENDCG
	}
	Fallback "Diffuse"
	CustomEditor "ASEMaterialInspector"
}
/*ASEBEGIN
Version=17800
1920;12;1920;1016;1952.191;885.3879;1.792312;True;True
Node;AmplifyShaderEditor.SamplerNode;20;-592.7949,493.9228;Inherit;True;Property;_NormalMap;NormalMap;7;0;Create;True;0;0;False;0;-1;None;2b2cf547aedb53f49aa7c81280f31e2c;True;0;True;bump;Auto;True;Object;-1;Auto;Texture2D;6;0;SAMPLER2D;;False;1;FLOAT2;0,0;False;2;FLOAT;0;False;3;FLOAT2;0,0;False;4;FLOAT2;0,0;False;5;FLOAT;1;False;5;FLOAT3;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.ColorNode;12;-537.2906,-251.7935;Inherit;False;Property;_BaseColour;BaseColour;0;0;Create;True;0;0;False;0;1,1,1,0;1,0.1556604,0.1556604,0;True;0;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.SamplerNode;10;-605.1874,-88.36989;Inherit;True;Property;_MainTextureCutoutA;MainTexture-Cutout(A);2;0;Create;True;0;0;False;0;-1;None;a589cdf2521b78544bcc522d0e9d1267;True;0;False;white;Auto;False;Object;-1;Auto;Texture2D;6;0;SAMPLER2D;;False;1;FLOAT2;0,0;False;2;FLOAT;0;False;3;FLOAT2;0,0;False;4;FLOAT2;0,0;False;5;FLOAT;1;False;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;42;-213.6483,627.3238;Inherit;False;2;2;0;FLOAT;0;False;1;FLOAT;-1;False;1;FLOAT;0
Node;AmplifyShaderEditor.ColorNode;30;-532.6793,95.00661;Inherit;False;Property;_SpecColour;SpecColour;4;0;Create;True;0;0;False;0;1,1,1,0;1,0.1556604,0.1556604,0;True;0;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;11;-216.3151,-158.5697;Inherit;False;2;2;0;COLOR;0,0,0,0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.RangedFloatNode;33;-572.1104,-345.9021;Inherit;False;Property;_Smoothness;Smoothness;6;0;Create;True;0;0;False;0;0.5;0;0;1;0;1;FLOAT;0
Node;AmplifyShaderEditor.RangedFloatNode;16;-100.7874,62.79404;Inherit;False;Property;_SelfIllumination;SelfIllumination;3;0;Create;True;0;0;False;0;0.1;0.1;0;2;0;1;FLOAT;0
Node;AmplifyShaderEditor.SamplerNode;19;-596.0758,263.1544;Inherit;True;Property;_SpecularColTextureSmoothA;SpecularColTexture-Smooth(A);5;0;Create;True;0;0;False;0;-1;None;bd3b91d0aef56674eb0e3ffc43c2ba19;True;0;False;white;Auto;False;Object;-1;Auto;Texture2D;6;0;SAMPLER2D;;False;1;FLOAT2;0,0;False;2;FLOAT;0;False;3;FLOAT2;0,0;False;4;FLOAT2;0,0;False;5;FLOAT;1;False;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.DynamicAppendNode;40;15.76758,535.9153;Inherit;False;FLOAT3;4;0;FLOAT;0;False;1;FLOAT;0;False;2;FLOAT;0;False;3;FLOAT;-1;False;1;FLOAT3;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;31;-211.8561,134.4375;Inherit;False;2;2;0;COLOR;0,0,0,0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;34;-192.1406,227.6378;Inherit;False;2;2;0;FLOAT;0;False;1;FLOAT;0;False;1;FLOAT;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;15;215.8322,16.85597;Inherit;False;2;2;0;COLOR;0,0,0,0;False;1;FLOAT;0;False;1;COLOR;0
Node;AmplifyShaderEditor.SwitchByFaceNode;39;257.7297,509.0308;Inherit;False;2;0;FLOAT3;0,0,0;False;1;FLOAT3;0,0,0;False;1;FLOAT3;0
Node;AmplifyShaderEditor.StandardSurfaceOutputNode;0;547.5989,-40.46951;Float;False;True;-1;2;ASEMaterialInspector;0;0;StandardSpecular;RRF_2sidedShaders/AS_twoSidedPBR_UnitySpecular;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;Off;0;False;-1;0;False;-1;False;0;False;-1;0;False;-1;False;0;Custom;0.5;True;True;0;True;TransparentCutout;;Geometry;All;14;all;True;True;True;True;0;False;-1;False;0;False;-1;255;False;-1;255;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;False;2;15;10;25;False;0.5;True;0;0;False;-1;0;False;-1;0;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;0;0,0,0,0;VertexOffset;True;False;Cylindrical;False;Relative;0;;1;-1;-1;-1;0;False;0;0;False;-1;-1;0;False;-1;0;0;0;False;0.1;False;-1;0;False;-1;16;0;FLOAT3;0,0,0;False;1;FLOAT3;0,0,0;False;2;FLOAT3;0,0,0;False;3;FLOAT3;0,0,0;False;4;FLOAT;0;False;5;FLOAT;0;False;6;FLOAT3;0,0,0;False;7;FLOAT3;0,0,0;False;8;FLOAT;0;False;9;FLOAT;0;False;10;FLOAT;0;False;13;FLOAT3;0,0,0;False;11;FLOAT3;0,0,0;False;12;FLOAT3;0,0,0;False;14;FLOAT4;0,0,0,0;False;15;FLOAT3;0,0,0;False;0
WireConnection;42;0;20;3
WireConnection;11;0;12;0
WireConnection;11;1;10;0
WireConnection;40;0;20;1
WireConnection;40;1;20;2
WireConnection;40;2;42;0
WireConnection;31;0;30;0
WireConnection;31;1;19;0
WireConnection;34;0;33;0
WireConnection;34;1;19;3
WireConnection;15;0;11;0
WireConnection;15;1;16;0
WireConnection;39;0;20;0
WireConnection;39;1;40;0
WireConnection;0;0;11;0
WireConnection;0;1;39;0
WireConnection;0;2;15;0
WireConnection;0;3;31;0
WireConnection;0;4;34;0
WireConnection;0;10;10;4
ASEEND*/
//CHKSM=BCC956158A9EA6757D317CC845029EB9A4CB952B