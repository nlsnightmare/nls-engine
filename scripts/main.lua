include("core/input")
include("core/entity")
local go2 = Entity("box.jpg", "b1");
local go1 = Entity("box.jpg", "b2");
go1.set_pos(1,2,0)
go2.set_pos(2,2,0)

-- print(go2.get_pos())


local x = 0
local dx = 3
function update(dt)
   go1.set_pos(go1.x + dx * dt, go1.y, go1.z)
   go2.set_pos(go2.x, go2.y + dx * dt, go2.z)

   if get_key(keys.W) then
      print("yay")
   elseif get_key(keys.F1) then
      print("ney")
   end


end

