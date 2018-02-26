include("core/input")
include("core/entity")
include("player")
-- local e = Entity("box.png", "obstacle")
local e1 = Entity("box.png", "obstacle")
local player = Player()
-- e.set_pos(2,4,0)
e1.set_pos(2,5,0)

local x = 0
local dx = 3

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end
end
