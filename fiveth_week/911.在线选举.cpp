/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

// @lc code=start
class TopVotedCandidate {
public:
    vector<int> vc;//记录每个时间段获得投票数最多的候选人
    vector<int> pes;//记录每个人获得的投票数
    vector<int> ts;//等于times，二分查找时有用
    int max=0;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        ts.assign(times.begin(),times.end());//将times的元素复制到ts容器中
        pes.assign(5000,0);//将pes初始化为带有5000个0的vector容器
        for(int i=0;i<persons.size();i++)
        {
            //此次选举的这个候选人的总票数加1
            pes[persons[i]]++;
            //此次选举的这个候选人的总票数大于等于之前最大候选人的票数
            if(pes[persons[i]]>=max)
            {
            	//更改max
                max=pes[persons[i]];
                //将在times[i]到times[i-1]时间段中的最大候选人放入容器
                vc.push_back(persons[i]);
            }
            //此次选举的这个候选人的总票数不大于之前最大候选人的票数
            else vc.push_back(vc[vc.size()-1]);//将上次的最大候选人放入容器
        }
    }
    //经过选举后，本题例子的vc动态数组则为[0,1,1,0,0,1,0]
    //对应的时间为[0,5,10,15,20,25,30]
    //在时间点3,12,25,15,24,8，应返回vc[0] = 0,vc[2] = 1..........
    int q(int t) {//二分查找
        int l=0,r=ts.size()-1;
        while(1)
        {
            if(l>r)break;
            int m=(l+r)/2;
            if(t==ts[m])return vc[m];//若查找的时间点恰好等于某个时间段的边界，直接返回,例如25直接返回vc[5]
            else if(t<ts[m])r=m-1;
            else l=m+1;
        }
       // vc[0] = 0;vc[1] = 1，用二分查找3，r为0，其他时间点查找也一样.
        return vc[r];
    }
};


/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

