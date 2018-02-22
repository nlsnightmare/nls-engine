include("core/input")
include("core/entity")
include("player")
local obj = Entity("box.jpg", "box 1")
local player = Player()


local x = 0
local dx = 3
function update(dt)
   -- obj.set_pos(obj.x + dx * dt, obj.y, obj.z)

   for _,e in pairs(entities) do
      e.update(dt)
   end
end

