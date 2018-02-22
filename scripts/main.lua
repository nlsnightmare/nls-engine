include("core/input")
include("core/entity")
include("player")
local player = Player()
local wall0 = Entity("box.png", "random")
local wall1 = Entity("box.jpg", "random")
local wall2 = Entity("container.jpg", "random")

player.set_scale(2,2,1)

wall0.set_pos(1,1,0)
wall1.set_pos(2,1,0)
wall2.set_pos(3,1,0)

local x = 0
local dx = 3

function update(dt)
   for _,e in pairs(entities) do
      e.update(dt)
   end
end

