### Using the tutorial for Git

---

* 创建版本库

  ```
  1.创建文件夹
  2.进入文件夹，用git init进行初始化
  ```

* 基本操作

  ```
  1.用 [git add file] 把文件提交到暂存区
  2.用 [git commit -m “注释”] 把文件提交到当前分区
  3.用 [git status] 查看当前状态
  4.用 [git reset --hard HEAD^] 可以退回到上一个提交版本
  	 HEAD^^表示上上个版本。
  	 HEAD-100表示上100个版本。
  	 也可以 git reset --hard 1094a [1094a是commit id]。
  5.用 [git log] 查看历史记录 (可加 --pretty=oneline)
  6.用 [git checkout -- file] 可以撤销你修改过的文件的内容 (未git add)
  7.用 [git reset HEAD file] 可以撤销你提交到暂存区的状态 (撤销git add)
  8.用 [git rm file] 可以删除文件 (删完记得git commit)
  ```

* 分支

  ```
  1. 查看分支：git branch
  2. 创建分支：git branch name
  3. 切换分支：git checkout name
  4. 创建+切换分支：git checkout -b name
  5. 合并某分支到当前分支：git merge name
  6. 删除分支：git branch -d name
  7. 强行删除分支：git branch -D name
  8. 合并某分支到当前分支但看不出曾经做过合并：git merge --no-ff -m "注释" name
  9. 储存当前工作现场：git stash
  10. 恢复工作现场：git stash apply (多个时可+名字 [stash@{0}])
  11. 删除工作现场：git stash drop (多个时可+名字 [stash@{0}])
  12. 恢复并删除工作现场：git stash pop (多个时可+名字 [stash@{0}])
  13. 查看工作现场：git stash list
  14. 重复提交的操作：git cherry-pick commit_id
  15. 查看分支合并图：git log --graph
  16. 把本地未push的分叉提交历史整理成直线：git rebase
  17. 查看远程库信息：git remote -v
  ```

* 标签

  ```
  1. 新建一个标签：git tag tagname，(默认为HEAD,也可以指定一个commit)
  2. 查看所有标签：git tag
  3. 指定标签信息：git tag -a tagname -m “注释”
  4. 删除标签：git tag -d v0.1
  ```

* 远程仓库`Github`

  ```
  1. 创建账号
  2. 新建一个Git仓库
  3. 在Github上添加Key
  4. 与本地仓库关联：git remote add origin git@github.com:michaelliao/learngit.git
  5. 把本地库的所有内容推送到远程库上：git push -u origin master (第一次加-u)
  ```

* 版本
 
 ```
 git reset/revert [--soft | --mixed | --hard]
 1. --mixed：保留源码，只是将commit和index回退到某个版本
 2. --soft: 保留源码，只是将commit回退到某个版本，不设计index回退
 3. --hard：源码，commit，index都回退
 4. reset：直接回退到指定版本，就像穿越过去一样（减少指定版本前面的commit）
 5. revert：新增一个commit，这个commit的版本是你想回退的那个（多了一条）
 ```
---

#### 总结

* 正常操作

  ```
  1.创建分支：git checkout -b name
  2.写好之后：git add name 
  3.提交：git commit -m "注释"
  4.回到主分支然后合并：git merge --no-ff -m "注释" name
  5.上传到远程库：git push 
  6.如果git push失败，那就git pull下来，更改冲突，然后重新git push
  ```

* 远程添加Key问题

  ```
  1. 进入.ssh
  2. 生成id_rsa.pub文件：ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
  3. 打开文件 id_rsa.pub
  4. 里面有秘钥，填入Github上,注意格式 
  ```

* 推送标签

  ```
  1.推送一个本地标签：git push origin <tagname>
  2.推送全部未推送过的本地标签：git push origin --tags
  3.删除一个远程标签：git push origin：refs/tags/tagname
  ```

  
 * 回退版本
 
  ```
  1. 如果你想要删除误提交的commit，用git reset，反之git revert。
  2. 已经push：git push -f origin 分支
      此操作强制让库代码回退到你当前版本，请确保commit版本正确，可能造成代码丢失
  ```

