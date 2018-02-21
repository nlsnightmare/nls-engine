include("core/input")
include("core/entity")
include("player")
local obj = Entity("box.jpg", "b1")
local player = Player()
obj.set_pos(1,2,0)

-- print(go2.get_pos())


local x = 0
local dx = 3
function update(dt)
   obj.set_pos(obj.x + dx * dt, obj.y, obj.z)

   player.update(dt)
end

