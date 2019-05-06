
## C++ 实现IoU和NMS

- IoU和NMS是目标检测中基本概念;
- 经常考察实现方法，记录一下.

```C++

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// reference: https://blog.csdn.net/qq_42189368/article/details/84292079

typedef struct Bbox {
	int x;
	int y;
	int w;
	int h;
	float score;
}Bbox;


float IoU(Bbox box1,Bbox box2)
{
	int x1 = std::max(box1.x, box2.x);
	int y1 = std::max(box1.y, box2.y);

	int x2 = std::min(box1.x + box1.w, box2.x + box2.w);
	int y2 = std::min(box1.y + box1.h, box2.y + box2.h);

	float over_area = ((x2 - x1 > 0) ? x2 - x1 : 0)*(y2 - y1 > 0 ? y2 - y1 : 0);
	float iou = over_area / (box1.w*box1.h + box2.w*box2.h - over_area);
	
	return iou;
}

bool cmp(Bbox box1, Bbox box2)
{
	return box1.score > box2.score;
}

vector<Bbox> nms(vector<Bbox>& boxs, float threshold)
{
	vector<Bbox> ret;
	while (boxs.size()>0)
	{
		sort(boxs.begin(), boxs.end(), cmp);
		ret.push_back(boxs[0]);

		for (int i = 0; i < boxs.size()-1; i++)
		{
			float iou = IoU(boxs[0], boxs[i + 1]);
			if (iou>threshold)
			{
				boxs.erase(boxs.begin()+i+1);
			}
		}
		boxs.erase(boxs.begin());
	}
}

int main()
{

	return 0;
}
```
