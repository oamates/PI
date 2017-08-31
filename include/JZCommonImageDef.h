#ifndef __JZ_COMMONIMAGEDEF_H__
#define __JZ_COMMONIMAGEDEF_H__

// 返回结果定义
enum JZ_RESULT
{
	JZ_UNKNOW = -1,
	JZ_SUCCESS,
	JZ_FAILED,
	JZ_INVAILD_PARAM,
};

// 像素格式，目前仅支持打包像素格式，分片像素格式以后扩展
enum JZ_PIXEL_FMT
{
	JZ_PIXFMT_BGR,
	JZ_PIXFMT_RGB,
	JZ_PIXFMT_BGRA,
	JZ_PIXFMT_RGBA,
	JZ_PIXFMT_YUVA,
};

struct JZImageBuf
{
	unsigned char*		color;			// 颜色通道
	int					pitch;			// 颜色通道一行的字节数
	unsigned char*		color_U;		// U 分片数据
	int					u_Pitch;		// U 分片数据一行的字节数
	unsigned char*		color_V;		// V 分片数据
	int					v_Pitch;		// V 分片数据一行的字节数
	unsigned char*		alpha;			// A 通道，部分像素格式未用（如不含 A 或者无分离的 A 通道）
	int					a_Pitch;		// A 通道一行的字节数
	JZ_PIXEL_FMT		pixel_fmt;		// 像素格式
	int					width;			// 图像宽度
	int					height;			// 图像高度

};

// 图像处理的一些基本的公共参数
struct JZCommonParam
{
	int size;
	JZCommonParam()
	{
		size = 2;
	}

	~JZCommonParam()
	{
		size = 0;
	}
};

struct JZImageProcessData
{
	JZImageBuf*		pSrcImage;			// 要进行图像处理的buffer
	JZImageBuf*		pDesImage;			// 用于存储图像处理后的buffer
};

#endif // !__JZ_COMMONIMAGEDEF_H__
